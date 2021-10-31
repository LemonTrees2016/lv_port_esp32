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
#include "dashboard.h"
#include "motor_page_new.h"
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
lv_obj_t * main_page = 0;
static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent=%p, son=%p, global=%p\n", obj->parent, obj, main_page);
        lv_group_remove_obj(main_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        SecondPage();
    }
}

static void event_handler1(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent=%p, son=%p, global=%p\n", obj->parent, obj, main_page);
        lv_group_remove_obj(main_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        dashboard();
    }
}

static void event_handler2(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent=%p, son=%p, global=%p\n", obj->parent, obj, main_page);
        lv_group_remove_obj(main_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        motor_page_new();
    }
}
lv_chart_series_t * ser1 = 0;
lv_chart_series_t * ser2 = 0;
static void event_handler_chart(lv_obj_t * obj, lv_event_t event)
{
    static uint8_t value;
    if(event == LV_EVENT_CLICKED) {
        printf("parent = %p, son = %p\n", obj, obj->parent);
        //lv_group_remove_obj(obj);
        //SecondPage();
    } else if (event == LV_EVENT_KEY) {
        printf("parent = %p, son = %p\n", obj, obj->parent);
        uint32_t * key = lv_event_get_data();
        if (*key == LV_KEY_UP) {
            value++;
            lv_chart_set_next(obj, ser1, value);
        } else if (*key == LV_KEY_DOWN) {
            value =  value ? (value - 1) : value;
            lv_chart_set_next(obj, ser1, value);
        }
        printf("press key = %d val = %d\n", *key, value);
    }
}
void lv_ex_chart_1(void)
{
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    /*Create a chart*/
    lv_obj_t * chart;
    chart = lv_chart_create(lv_scr_act(), NULL);
    lv_obj_set_size(chart, SCREEN_WIDTH, SCREEN_HEIGH);
    lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

    lv_group_add_obj(group, chart);
    lv_obj_set_event_cb(chart, event_handler_chart);

    /*Add two data series*/
    ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
    ser2 = lv_chart_add_series(chart, LV_COLOR_GREEN);

    /*Set the next points on 'ser1'*/
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 30);
    lv_chart_set_next(chart, ser1, 70);
    lv_chart_set_next(chart, ser1, 90);

    /*Directly set points on 'ser2'*/
    ser2->points[0] = 90;
    ser2->points[1] = 70;
    ser2->points[2] = 65;
    ser2->points[3] = 65;
    ser2->points[4] = 65;
    ser2->points[5] = 65;
    ser2->points[6] = 65;
    ser2->points[7] = 65;
    ser2->points[8] = 65;
    ser2->points[9] = 65;

    lv_chart_refresh(chart); /*Required after direct set*/
}

static void event_handler3(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent=%p, son=%p, global=%p\n", obj->parent, obj, main_page);
        lv_group_remove_obj(main_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        lv_ex_chart_1();
    }
}

void lv_ex_page_1(void)
{
    /*Create a list*/
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    /*Create a page*/
    lv_obj_t * page = lv_page_create(lv_scr_act(), NULL);
    lv_obj_set_size(page, SCREEN_WIDTH, SCREEN_HEIGH);
    lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_group_add_obj(group, page);

    uint16_t posY = 0;
    uint8_t delta = 20;
    /*Create a label on the page*/
    lv_obj_t * label = lv_label_create(page, NULL);
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#0000ff 1 Lorem ipsum dolor sit amet#");

    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 2 Lorem ipsum dolor sit amet#");

    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 3 Lorem ipsum dolor sit amet#");

    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 4 Lorem ipsum dolor sit amet#");

    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 5 Lorem ipsum dolor sit amet#");

    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#00ff00 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#00ff00 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#00ff00 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#00ff00 6 Lorem ipsum dolor sit amet#");
    
    label = lv_label_create(page, NULL);
    posY += delta;
    lv_obj_set_pos(label, 0, posY); 
    lv_label_set_recolor(label, true); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(label, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(label, "#ff0000 6 Lorem ipsum dolor sit amet#");
#if 0
    /*Create a chart*/
    lv_obj_t * chart;
    chart = lv_chart_create(page, NULL);
    posY += delta * 10;
    lv_obj_set_pos(chart, 0, posY);     
    lv_obj_set_width(chart, lv_page_get_width_fit(page));          /*Set the label width to max value to not show hor. scroll bars*/

    lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

    /*Add two data series*/
    ser1 = lv_chart_add_series(chart, LV_COLOR_RED);

    /*Set the next points on 'ser1'*/
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 30);
    lv_chart_set_next(chart, ser1, 70);
    lv_chart_set_next(chart, ser1, 90);
#endif
}

static void event_handler4(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("parent=%p, son=%p, global=%p\n", obj->parent, obj, main_page);
        lv_group_remove_obj(main_page);
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
        lv_ex_page_1();
    }
}

void MainPage()
{
    /*Create a list*/
    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    lv_obj_t * list1 = lv_list_create(lv_scr_act(), NULL);
    main_page = list1;
    lv_group_add_obj( group, main_page );
    lv_obj_set_size(list1, SCREEN_WIDTH, SCREEN_HEIGH);
    lv_obj_align(list1, NULL, LV_ALIGN_CENTER, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t * list_btn;

    //printf("start--\n");
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_DRIVE, "MotorControl");
    lv_obj_set_event_cb(list_btn, event_handler);
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "dashboard");
    lv_obj_set_event_cb(list_btn, event_handler1);
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "new_test");
    lv_obj_set_event_cb(list_btn, event_handler2);
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_DIRECTORY, "CHART");
    lv_obj_set_event_cb(list_btn, event_handler3);
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "page");
    lv_obj_set_event_cb(list_btn, event_handler4);
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "rev4");
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "rev5");
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "rev6");
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "rev7");
    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "rev8");
    //printf("MainPage parent=%p, scr=%p, global=%p , grandpa=%p \n", list_btn->parent, scr, list1, scr->parent);
    //printf("end--\n");
    
    //printf("MainPage parent=%p, son=%p, global=%p\n", list_btn->parent, list_btn, main_page);
    return;
}
