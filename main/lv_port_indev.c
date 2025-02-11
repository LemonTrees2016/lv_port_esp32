/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "button_int.h"
#include "esp_log.h"
#include <stdio.h>
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "xpt2046.h"

/*********************
 *      DEFINES
 *********************/
#define LV_USE_INDEV_TOUCHPAD 	0x1u
#define LV_USE_INDEV_MOUSE	 	0x2u
#define LV_USE_INDEV_KEYPAD 	0x4u
#define LV_USE_INDEV_ENCODER 	0x8u
#define LV_USE_INDEV_BUTTON 	0x10u
#define LV_USE_INDEV  	LV_USE_INDEV_KEYPAD//(LV_USE_INDEV_KEYPAD | LV_USE_INDEV_ENCODER)			
                        // 使用Touchpad 和 keypad 

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
/************************************************
 * 二、根据注释 我们找到 STATIC PROTOTYPES，按类型
 * 添加预处理语句
 ************************************************/
#if ( LV_USE_INDEV & LV_USE_INDEV_TOUCHPAD ) == LV_USE_INDEV_TOUCHPAD
static void touchpad_init(void);
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);
#endif

#if ( LV_USE_INDEV & LV_USE_INDEV_MOUSE ) == LV_USE_INDEV_MOUSE
static void mouse_init(void);
static bool mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool mouse_is_pressed(void);
static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y);
#endif

#if ( LV_USE_INDEV & LV_USE_INDEV_KEYPAD ) == LV_USE_INDEV_KEYPAD
static void keypad_init(void);
static bool keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);
#endif

#if ( LV_USE_INDEV & LV_USE_INDEV_ENCODER ) == LV_USE_INDEV_ENCODER
static void encoder_init(void);
static bool encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void encoder_handler(void);
#endif

#if ( LV_USE_INDEV & LV_USE_INDEV_BUTTON ) == LV_USE_INDEV_BUTTON
static void button_init(void);
static bool button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);
#endif



/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
lv_indev_t * indev_button;
lv_group_t * group = 0;
static int32_t encoder_diff;
static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_port_indev_init(void)
{
    /* Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    // 不动
    lv_indev_drv_t indev_drv;

	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
#if ( LV_USE_INDEV & LV_USE_INDEV_TOUCHPAD ) == LV_USE_INDEV_TOUCHPAD
    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    touchpad_init();

	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
#endif
#if ( LV_USE_INDEV & LV_USE_INDEV_MOUSE ) == LV_USE_INDEV_MOUSE
    /*------------------
     * Mouse
     * -----------------*/

    /*Initialize your touchpad if you have*/
    mouse_init();

    /*Register a mouse input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read;
    indev_mouse = lv_indev_drv_register(&indev_drv);

    /*Set cursor. For simplicity set a HOME symbol now.*/
    lv_obj_t * mouse_cursor = lv_img_create(lv_disp_get_scr_act(NULL), NULL);
    lv_img_set_src(mouse_cursor, LV_SYMBOL_HOME);
    lv_indev_set_cursor(indev_mouse, mouse_cursor);
#endif
#if ( LV_USE_INDEV & LV_USE_INDEV_KEYPAD ) == LV_USE_INDEV_KEYPAD
    /*------------------
     * Keypad
     * -----------------*/

	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
    /*Initialize your keypad or keyboard if you have*/
    keypad_init();

    /*Register a keypad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);

    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_keypad, group);` */
    group = lv_group_create();
    lv_indev_set_group(indev_keypad, group);

	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
#endif
#if ( LV_USE_INDEV & LV_USE_INDEV_ENCODER ) == LV_USE_INDEV_ENCODER
    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    encoder_init();

	ESP_LOGI("gpio_task_example","[%d]", __LINE__);
    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_read;
    indev_encoder = lv_indev_drv_register(&indev_drv);

    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_encoder, group);` */
#endif
#if ( LV_USE_INDEV & LV_USE_INDEV_BUTTON ) == LV_USE_INDEV_BUTTON
    /*------------------
     * Button
     * -----------------*/

    /*Initialize your button if you have*/
    button_init();

    /*Register a button input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_BUTTON;
    indev_drv.read_cb = button_read;
    indev_button = lv_indev_drv_register(&indev_drv);

    /*Assign buttons to points on the screen*/
    static const lv_point_t btn_points[2] = {
            {10, 10},   /*Button 0 -> x:10; y:10*/
            {40, 100},  /*Button 1 -> x:40; y:100*/
    };
    lv_indev_set_button_points(indev_button, btn_points);
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/
#if ( LV_USE_INDEV & LV_USE_INDEV_TOUCHPAD ) == LV_USE_INDEV_TOUCHPAD
/*Initialize your touchpad*/
static void touchpad_init(void)
{
    /*Your code comes here*/
    xpt2046_init();
}

/* Will be called by the library to read the touchpad */
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    return xpt2046_read(indev_drv, data);

    static lv_coord_t last_x = 0;
    static lv_coord_t last_y = 0;

    /*Save the pressed coordinates and the state*/
    if(touchpad_is_pressed()) {
        touchpad_get_xy(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
    data->point.x = last_x;
    data->point.y = last_y;

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}
#endif
/*------------------
 * Mouse
 * -----------------*/
#if ( LV_USE_INDEV & LV_USE_INDEV_MOUSE ) == LV_USE_INDEV_MOUSE
/* Initialize your mouse */
static void mouse_init(void)
{
    /*Your code comes here*/
}

/* Will be called by the library to read the mouse */
static bool mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    /*Get the current x and y coordinates*/
    mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the mouse button is pressed or released*/
    if(mouse_is_pressed()) {
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

/*Return true is the mouse button is pressed*/
static bool mouse_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the mouse is pressed*/
static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}
#endif
/*------------------
 * Keypad
 * -----------------*/
#if ( LV_USE_INDEV & LV_USE_INDEV_KEYPAD ) == LV_USE_INDEV_KEYPAD
/* Initialize your keypad */
static void keypad_init(void)
{
    /*Your code comes here*/
    app_main_gpio();
}

/* Will be called by the library to read the mouse */
static bool keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get the current x and y coordinates*/
    //mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;
        last_key = act_key;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

extern xQueueHandle gpio_evt_queue_key;
extern uint8_t gpio_flg[40];
/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    uint32_t io_num = 0;
#if 0
    LV_KEY_UP        = 17,  /*0x11*/
    LV_KEY_DOWN      = 18,  /*0x12*/
    LV_KEY_RIGHT     = 19,  /*0x13*/
    LV_KEY_LEFT      = 20,  /*0x14*/
    LV_KEY_ESC       = 27,  /*0x1B*/
    LV_KEY_DEL       = 127, /*0x7F*/
    LV_KEY_BACKSPACE = 8,   /*0x08*/
    LV_KEY_ENTER     = 10,  /*0x0A, '\n'*/
    LV_KEY_NEXT      = 9,   /*0x09, '\t'*/
    LV_KEY_PREV      = 11,  /*0x0B, '*/
    LV_KEY_HOME      = 2,   /*0x02, STX*/
    LV_KEY_END       = 3,   /*0x03, ETX*/
#endif
    uint8_t keyMapTab[][2]= {
        {GPIO_INPUT_IO_SWITCH_DOWN, LV_KEY_DOWN},
        {GPIO_INPUT_IO_SWITCH_UP, LV_KEY_UP},
        {GPIO_INPUT_IO_SWITCH_LEFT, LV_KEY_LEFT},
        {GPIO_INPUT_IO_SWITCH_RIGHT, LV_KEY_RIGHT},
        {GPIO_INPUT_IO_SWITCH_OK, LV_KEY_ENTER},
        {GPIO_INPUT_IO_SWITCH_A, LV_KEY_PREV},
        {GPIO_INPUT_IO_SWITCH_B, LV_KEY_NEXT},
        {GPIO_INPUT_IO_SWITCH_C, LV_KEY_HOME},
        {GPIO_INPUT_IO_SWITCH_D, LV_KEY_END},
        {GPIO_INPUT_IO_C, LV_KEY_UP},
        {GPIO_INPUT_IO_A, LV_KEY_DOWN},
        {GPIO_INPUT_IO_ROTATE, LV_KEY_ENTER},
    };

    for (uint8_t i = 0; i < 40; i++) {
        if (gpio_flg[i] == 1) {
            gpio_flg[i] = 0;
	        ESP_LOGI("gpio_task_example","GPIO[%d]", i);
            for (uint8_t j = 0; j < sizeof(keyMapTab) / (2* sizeof(keyMapTab[0][0])); j++) {
                if (keyMapTab[j][0] == i) {
                    return keyMapTab[j][1];
                }
            }
        }
    }

    return 0;
    /*Your code comes here*/
    if(xQueueReceive(gpio_evt_queue_key, &io_num, portMAX_DELAY))
		{
			//ProcRotate();
            switch(io_num) {
                case GPIO_INPUT_IO_SWITCH_DOWN: return 1;
                case GPIO_INPUT_IO_SWITCH_UP: return 2;
                case GPIO_INPUT_IO_SWITCH_LEFT: return 3;
                case GPIO_INPUT_IO_SWITCH_RIGHT: return 4;
                case GPIO_INPUT_IO_SWITCH_OK: return 5;
                case 255: return 0;
            }
	        ESP_LOGI("gpio_task_example","GPIO[%d]", io_num);
		}
    
    return 0;
}
#endif
/*------------------
 * Encoder
 * -----------------*/
#if ( LV_USE_INDEV & LV_USE_INDEV_ENCODER ) == LV_USE_INDEV_ENCODER
/* Initialize your keypad */
static void encoder_init(void)
{
    /*Your code comes here*/
}

/* Will be called by the library to read the encoder */
static bool encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    data->enc_diff = encoder_diff;
    data->state = encoder_state;

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    /*Your code comes here*/

    encoder_diff += 0;
    encoder_state = LV_INDEV_STATE_REL;
}
#endif
/*------------------
 * Button
 * -----------------*/
#if ( LV_USE_INDEV & LV_USE_INDEV_BUTTON ) == LV_USE_INDEV_BUTTON
/* Initialize your buttons */
static void button_init(void)
{
    /*Your code comes here*/
}

/* Will be called by the library to read the button */
static bool button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for(i = 0; i < 2; i++) {
        /*Return the pressed button's ID*/
        if(button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id)
{

    /*Your code comes here*/

    return false;
}
#endif
#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
