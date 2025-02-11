/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "mcpwm_control.h"

/* Littlevgl specific */
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "lvgl_helpers.h"
#include "button_int.h"
#include "lv_port_indev.h"
#include "main_page.h"
#include "motor_page.h"



#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    #if defined CONFIG_LV_USE_DEMO_WIDGETS
        #include "lv_examples/src/lv_demo_widgets/lv_demo_widgets.h"
    #elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
        #include "lv_examples/src/lv_demo_keypad_encoder/lv_demo_keypad_encoder.h"
    #elif defined CONFIG_LV_USE_DEMO_BENCHMARK
        #include "lv_examples/src/lv_demo_benchmark/lv_demo_benchmark.h"
    #elif defined CONFIG_LV_USE_DEMO_STRESS
        #include "lv_examples/src/lv_demo_stress/lv_demo_stress.h"
    #else
        #error "No demo application selected."
    #endif
#endif

/*********************
 *      DEFINES
 *********************/
#define TAG "demo"
#define LV_TICK_PERIOD_MS 1
extern lv_group_t * group;
extern int g_Cnt;
/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);
static void create_demo_application(void);
lv_obj_t *table_view_obj;
/**********************
 *   APPLICATION MAIN
 **********************/
void app_main() {

    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    xTaskCreatePinnedToCore(guiTask, "gui", 4096*2, NULL, 0, NULL, 1);
    //app_main_gpio();
	McPwmCtrl_AppMain();
}

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter) {

    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t* buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    lv_color_t* buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820         \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A    \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D     \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306

    /* Actual size in pixels, not bytes. */
    size_in_px *= 8;
#endif

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
#endif

    disp_drv.buffer = &disp_buf;

    disp_drv.sw_rotate = 1;
    disp_drv.rotated = LV_DISP_ROT_180;

    //lv_disp_set_rotation(&disp_drv, LV_DISP_ROT_180);
    lv_disp_drv_register(&disp_drv);

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    lv_port_indev_init();

    /* Create the demo application */
    create_demo_application();

    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
       }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

#if 0
esp_timer_handle_t test_p_handle = 0;
lv_obj_t* obj_gauage = 0;

void test_timer_periodic_cb(void *arg) {
    static uint8_t rotate_ang = 0;
    //ESP_LOGI("test_timer_periodic_cb", "Enter timer int");
    if (obj_gauage == 0) {
        ESP_LOGI("test_timer_periodic_cb", "arg null");
        return;
    }

    //ESP_LOGI("test_timer_periodic_cb", "Enter timer int");
    rotate_ang += 1;
    rotate_ang %= 120;
    lv_gauge_set_value((lv_obj_t*)obj_gauage, 0, rotate_ang);
    lv_event_send_refresh((lv_obj_t*)obj_gauage);
}

static void time_task(lv_obj_t* obj)
{
    //定义一个周期重复运行的定时器结构体
    esp_timer_create_args_t test_periodic_arg = { 
            .callback = &test_timer_periodic_cb, //设置回调函数
            .arg = obj, //不携带参数
            .name = "TestPeriodicTimer" //定时器名字
            };

   //开始创建一个重复周期的定时器并且执行
	esp_err_t err = esp_timer_create(&test_periodic_arg, &test_p_handle);
	err = esp_timer_start_periodic(test_p_handle, 100 * 3000);
}

void fill_test()
{
    static lv_color_t needle_colors[3];
    needle_colors[0] = LV_COLOR_RED;
    needle_colors[1] = LV_COLOR_ORANGE;
    needle_colors[2] = LV_COLOR_PURPLE;
/*
    static lv_style_t gauge_style;
    lv_style_copy(&gauge_style, &lv_style_pretty_color);
    gauge_style.line.width = 1;
  */  
    lv_obj_t* gaugel = lv_gauge_create(lv_scr_act(), NULL);
    lv_disp_set_rotation(NULL, 180);
    obj_gauage = gaugel;
    ESP_LOGI("test_timer_periodic_cb", "%p", obj_gauage);
    lv_obj_set_size(gaugel, 128, 128);

    //lv_gauge_set_style(gaugel, LV_GAUGE_STYLE_MAIN, &gauge_style);

    lv_gauge_set_needle_count(gaugel, 1, needle_colors);
    lv_gauge_set_range(gaugel, 0, 120);
    lv_gauge_set_value(gaugel, 0, 10);

    //time_task(gaugel);
    return;
}

void gauge_test(void)
{
    static lv_color_t needle_colors[3];
    needle_colors[0] = LV_COLOR_RED;
    needle_colors[1] = LV_COLOR_ORANGE;
    needle_colors[2] = LV_COLOR_PURPLE;
/*
    static lv_style_t gauge_style;
    lv_style_copy(&gauge_style, &lv_style_pretty_color);
    gauge_style.line.width = 1;
  */  
    lv_obj_t* gaugel = lv_gauge_create(lv_scr_act(), NULL);
    obj_gauage = gaugel;
    ESP_LOGI("test_timer_periodic_cb", "%p", obj_gauage);
    lv_obj_set_size(gaugel, 128, 128);

    //lv_gauge_set_style(gaugel, LV_GAUGE_STYLE_MAIN, &gauge_style);

    lv_gauge_set_needle_count(gaugel, 1, needle_colors);
    lv_gauge_set_range(gaugel, 0, 120);
    lv_gauge_set_value(gaugel, 0, 10);


    // 设置；
    lv_obj_t* two = lv_obj_create(NULL, NULL);
    lv_scr_load(two);
    lv_scr_load_anim(two, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 5000, true);
    lv_obj_t* label = lv_label_create(two, NULL);
    lv_obj_set_size(two, LV_HOR_RES, LV_VER_RES);
    lv_obj_align(label, two, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_local_bg_color(two, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLUE);
    lv_label_set_text(label, "TWO");
    vTaskDelay(pdMS_TO_TICKS(2000));


    // 设置；
    lv_obj_t* three = lv_obj_create(NULL, NULL);
    lv_scr_load(three);
    lv_scr_load_anim(two, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 5000, true);
    lv_obj_t* label2 = lv_label_create(three, NULL);
    lv_obj_set_size(three, LV_HOR_RES, LV_VER_RES);
    lv_obj_align(label2, three, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_local_bg_color(three, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GREEN);
    lv_label_set_text(label2, "three");
    vTaskDelay(pdMS_TO_TICKS(2000));

    // 设置；
    lv_obj_t* four = lv_obj_create(NULL, NULL);
    lv_scr_load(four);
    lv_scr_load_anim(two, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 5000, true);
    lv_obj_t* label3 = lv_label_create(four, NULL);
    lv_obj_set_size(four, LV_HOR_RES, LV_VER_RES);
    lv_obj_align(label3, four, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_local_bg_color(four, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
    lv_label_set_text(label3, "four");
    lv_scr_load_anim(four, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 5000, true);
    vTaskDelay(pdMS_TO_TICKS(2000));


    //lv_scr_load_anim(gaugel, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 5000, true);

}

#endif

static void create_demo_application(void)
{
    /* When using a monochrome display we only show "Hello World" centered on the
     * screen */
    #define CONFIG_LV_TFT_DISPLAY_MONOCHROME;
    
#if defined CONFIG_LV_TFT_DISPLAY_MONOCHROME || \
    defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S
    //lv_ex_tileview_1();
    //table_view();
    MainPage();
    //gauge_test();
#else
    /* Otherwise we show the selected demo */

    #if defined CONFIG_LV_USE_DEMO_WIDGETS
        lv_demo_widgets();
    #elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
        lv_demo_keypad_encoder();
    #elif defined CONFIG_LV_USE_DEMO_BENCHMARK
        lv_demo_benchmark();
    #elif defined CONFIG_LV_USE_DEMO_STRESS
        lv_demo_stress();
    #else
        #error "No demo application selected."
    #endif
#endif
}

static void lv_tick_task(void *arg) {
    (void) arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}
