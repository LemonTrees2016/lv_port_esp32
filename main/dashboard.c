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
#include "second_page.h"
#include "screen_cfg.h"

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
#define TAG "main_page"
extern lv_group_t * group;
extern int g_Cnt;

static char tmp[10] = {48, 48, 49, 0};
static int32_t value = 0;

static int32_t speedvalue = 1;
static int32_t rotatvalue = 22;
static int32_t tempvalue = 333;
static int32_t humidvalue = 4444;
/**********************
 *  STATIC PROTOTYPES
 **********************/
static void set_text(int32_t value)
{
    tmp[0] = value / 100 + 48;
    tmp[1] = (value % 100) / 10 + 48;
    tmp[2] = (value % 10) + 48;
    tmp[3] = 0;
}

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {

    } else if (event == LV_EVENT_KEY) {

    }
}

//static lv_style_t font_style;
//lv_style_init(&font_style);
//lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_montserrat_28);
//lv_obj_add_style(label1, LV_LABEL_PART_MAIN, &font_style);

void lv_ex_table_1(void)
{

}

esp_timer_handle_t test_p_handle = 0;
lv_obj_t* label = 0;
const char* formate = "speed=%05d\nrotat=%05d\ntempe=%05d\nhumid=%05d\nspeed=%05d\nrotat=%05d\ntempe=%05d\nhumid=%05d";

void test_timer_periodic_cb(void *arg) {
    static uint8_t rotate_ang = 0;
    //ESP_LOGI("test_timer_periodic_cb", "Enter timer int");
    if (label == 0) {
        ESP_LOGI("test_timer_periodic_cb", "arg null");
        return;
    }

    //ESP_LOGI("test_timer_periodic_cb", "Enter timer int");
    rotate_ang += 1;
    rotate_ang %= 120;
    lv_label_set_text_fmt(label, formate, speedvalue + rotate_ang, rotatvalue + rotate_ang, 
                            tempvalue + rotate_ang, humidvalue +rotate_ang,
                            speedvalue + rotate_ang, rotatvalue + rotate_ang, 
                            tempvalue + rotate_ang, humidvalue + rotate_ang);
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



extern lv_font_t lv_font_courier_18;
void dashboard()
{
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

#if 0
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    lv_obj_t * speed = lv_label_create(scr, NULL);
    lv_obj_add_style(speed, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_set_width(speed, 79);
    lv_obj_align(speed, scr, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    lv_label_set_align(speed, LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text_fmt(speed, "%8s", "   speed");

    lv_obj_t * speedval = lv_label_create(scr, NULL);
    lv_obj_add_style(speedval, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(speedval, scr, LV_ALIGN_IN_TOP_LEFT, 80, 0);
    lv_label_set_align(speedval, LV_LABEL_ALIGN_LEFT);
    lv_label_set_text_fmt(speedval, "%07d", speedvalue);

    lv_obj_t * rotat = lv_label_create(scr, NULL);
    lv_obj_add_style(rotat, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_set_width(rotat, 79);
    lv_obj_align(rotat, scr, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_label_set_text_fmt(rotat, "%8s", "   rotat");

    lv_obj_t * rotatval = lv_label_create(scr, NULL);
    lv_obj_add_style(rotatval, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(rotatval, scr, LV_ALIGN_IN_TOP_LEFT, 80, 20);
    lv_label_set_align(rotatval, LV_LABEL_ALIGN_LEFT);
    lv_label_set_text_fmt(rotatval, "%07d", rotatvalue);

    
    lv_obj_t * temp = lv_label_create(scr, NULL);
    lv_obj_add_style(temp, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(temp, scr, LV_ALIGN_IN_TOP_LEFT, 0, 40);
    lv_label_set_text_fmt(temp, "%8s", "    temp");

    lv_obj_t * tempval = lv_label_create(scr, NULL);
    lv_obj_add_style(tempval, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(tempval, scr, LV_ALIGN_IN_TOP_LEFT, 80, 40);
    lv_label_set_align(tempval, LV_LABEL_ALIGN_LEFT);
    lv_label_set_text_fmt(tempval, "%07d", tempvalue);

    
    lv_obj_t * humid = lv_label_create(scr, NULL);
    lv_obj_add_style(humid, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(humid, scr, LV_ALIGN_IN_TOP_LEFT, 0, 60);
    lv_label_set_text_fmt(humid, "%8s", "   humid");

    lv_obj_t * humidval = lv_label_create(scr, NULL);
    lv_obj_add_style(humidval, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(humidval, scr, LV_ALIGN_IN_TOP_LEFT, 80, 60);
    lv_label_set_align(humidval, LV_LABEL_ALIGN_LEFT);
    lv_label_set_text_fmt(humidval, "%07d", humidvalue);

#elif 0
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_montserrat_48);
    
    lv_obj_t * huge = lv_label_create(scr, NULL);
    lv_obj_add_style(huge, LV_LABEL_PART_MAIN, &font_style);
    lv_obj_align(huge, scr, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    lv_label_set_align(huge, LV_LABEL_ALIGN_LEFT);
    lv_label_set_text_fmt(huge, "%4d", humidvalue);

#else
    
    /*Create a page*/
    lv_obj_t * page = lv_page_create(lv_scr_act(), NULL);
    lv_group_add_obj( group, page);
    lv_obj_set_size(page, SCREEN_WIDTH, SCREEN_HEIGH);
    lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);

    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_courier_18);

    /*Create a label on the page*/
    label = lv_label_create(page, NULL);
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text_fmt(label, formate, 
                                  speedvalue, rotatvalue, tempvalue, humidvalue,
                                  speedvalue, rotatvalue, tempvalue, humidvalue);
    
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &font_style);
    time_task(label);
#endif
    lv_ex_table_1();
}
