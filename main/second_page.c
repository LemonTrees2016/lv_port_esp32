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
#include "motor_page.h"
#include "main_page.h"
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
/**********************
 *  STATIC PROTOTYPES
 **********************/
lv_obj_t * second_page = 0;
static void event_handler1(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        lv_group_remove_obj(second_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        MainPage();
    }
}

static void event_handler2(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        lv_group_remove_obj(second_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        motor_page();
    }
}
void SecondPage()
{
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);
    //lv_scr_load_anim(scr, LV_SCR_LOAD_ANIM_OVER_LEFT, 1000, 0, true );
    //lv_obj_set_state(obj, part, LV_STATE...);

    /*Create a list*/
    lv_obj_t * list1 = lv_list_create(lv_scr_act(), NULL);
    second_page = list1;
    //lv_list_set_layout(list1, LV_LAYOUT_ROW_MID);
    lv_group_add_obj(group, list1);
    
    lv_obj_set_size(list1, SCREEN_WIDTH, SCREEN_HEIGH);
    lv_obj_align(list1, NULL, LV_ALIGN_CENTER, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t * list_btn;

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BELL, "linemeter");
    lv_obj_set_event_cb(list_btn, event_handler2);
    
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BATTERY_FULL, "ESC1");
    lv_obj_set_event_cb(list_btn, event_handler1);
    return;
}
