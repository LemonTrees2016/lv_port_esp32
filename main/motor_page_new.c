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

#include "screen_cfg.h"
/*********************
 *      DEFINES
 *********************/
#define TAG "main_page"
extern lv_group_t * group;
extern int g_Cnt;

char tmp[10];
static int32_t value = 0;
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

static void motor_page_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent = %p, son = %p\n", obj, obj->parent);
        lv_group_remove_obj(obj);
        SecondPage();
    } else if (event == LV_EVENT_KEY) {
        printf("parent = %p, son = %p\n", obj, obj->parent);
        uint32_t * key = lv_event_get_data();
        if (*key == LV_KEY_UP) {
            value++;
            
        } else if (*key == LV_KEY_DOWN) {
            value =  value ? (value - 1) : value;
        }
        printf("press key = %d val = %d\n", *key, value);
        //lv_label_set_text(obj, tmp);
        //lv_linemeter_set_value(obj->parent, value);
        //printf("%s", tmp);
        set_text(value);
        lv_label_set_text(obj->child_ll.head, tmp);
        lv_linemeter_set_value(obj, value);

        // 设置PWM波形输出
        g_Cnt = value;
        SetPwmFlag();
    }
}

//extern lv_font_t lv_font_montserrat_28;
//static lv_style_t font_style;
//lv_style_init(&font_style);
//lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_montserrat_28);
//lv_obj_add_style(label1, LV_LABEL_PART_MAIN, &font_style);


#define CANVAS_WIDTH  160
#define CANVAS_HEIGHT  128

void lv_ex_canvas_1(void)
{
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);

    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.color = LV_COLOR_YELLOW;

    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

    lv_obj_t * canvas = lv_canvas_create(lv_scr_act(), NULL);
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_canvas_fill_bg(canvas, LV_COLOR_SILVER, LV_OPA_COVER);

    lv_canvas_draw_rect(canvas, 70, 60, 60, 40, &rect_dsc);

    //lv_canvas_draw_text(canvas, 40, 20, 100, &label_dsc, "Some text on text canvas", LV_LABEL_ALIGN_LEFT);

    /* Test the rotation. It requires an other buffer where the orignal image is stored.
     * So copy the current image to buffer and rotate it to the canvas */
    static lv_color_t cbuf_tmp[CANVAS_WIDTH * CANVAS_HEIGHT];
    memcpy(cbuf_tmp, cbuf, sizeof(cbuf_tmp));
    lv_img_dsc_t img;
    img.data = (void *)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = CANVAS_WIDTH;
    img.header.h = CANVAS_HEIGHT;

    lv_canvas_fill_bg(canvas, LV_COLOR_SILVER, LV_OPA_COVER);
    lv_canvas_transform(canvas, &img, 0, LV_IMG_ZOOM_NONE, 0, 0, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, true);
}

extern lv_font_t lv_font_courier_18;
void motor_page_new()
{
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);
 
    lv_ex_canvas_1();
}