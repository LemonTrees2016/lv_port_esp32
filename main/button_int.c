#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_task_wdt.h"

#include "esp_timer.h"
#include "esp_sleep.h"
/* Littlevgl specific */
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "lvgl_helpers.h"
#include "mcpwm_control.h"
#include "button_int.h"




uint32_t g_switch_flag=0;

uint32_t g_switch1_flag=0;

char g_LevelRcd[4] = {0};
unsigned int g_rcdIdx = 0;
int g_Cnt = 0;
unsigned int g_ReadFlg = 0;
int g_Cnt1 = 0;
xQueueHandle gpio_evt_queue_key = NULL; //事件列表

typedef struct {
	uint32_t io_num;
	char switchName[30];
} switchStru;

switchStru switchName[13] = {
	{GPIO_INPUT_IO_SWITCH_UP, "UP"},
	{GPIO_INPUT_IO_SWITCH_DOWN, "DOWN"},
	{GPIO_INPUT_IO_SWITCH_LEFT, "LEFT"},
	{GPIO_INPUT_IO_SWITCH_RIGHT, "RIGHT"},
	{GPIO_INPUT_IO_SWITCH_OK, "OK"},
	{GPIO_INPUT_IO_SWITCH_SELECT, "SELECT"},
	{GPIO_INPUT_IO_SWITCH_A, "A"},
	{GPIO_INPUT_IO_SWITCH_B, "B"},
	{GPIO_INPUT_IO_SWITCH_C, "C"},
	{GPIO_INPUT_IO_SWITCH_D, "D"},
	{GPIO_INPUT_IO_ROTATE, "ROTATE"},
	{GPIO_INPUT_IO_A, "ROTATE"},
	{GPIO_INPUT_IO_C, "ROTATE"},
	
};

char* GetSwitchName(uint32_t io_num)
{

	for (int i = 0; i < 13; i++) {
		if (io_num == switchName[i].io_num) {
			return switchName[i].switchName;
		}
	}

	return "NULL";
}

typedef struct {
	uint8_t gpio_id;
	uint8_t index;
	int8_t gp_st[10];
	double avg;
	double thresh;
} gpio_cfg;


extern lv_obj_t* obj_gauage;
extern lv_obj_t* lmeter1;
extern lv_obj_t* label1;

uint8_t gpio_flg[40] = {0};

// 中断处理，
static void gpio_proc(void* arg)
{		
	static gpio_cfg gp_cfg[] = {
		{GPIO_INPUT_IO_SWITCH_UP, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_DOWN, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_LEFT, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_RIGHT, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_OK, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_SELECT, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_A, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_B, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_C, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_SWITCH_D, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_ROTATE, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_A, 0, {0}, 0.0, 0.75},
		{GPIO_INPUT_IO_C, 0, {0}, 0.0, 0.75},
		
	};

	double delta = 0.0;
#if 0
	#define SEND_MSG(gpio_evt_queue_key, portId, portId1) xQueueSendFromISR(gpio_evt_queue_key, &(portId), NULL); \
    								xQueueSendFromISR(gpio_evt_queue_key, &(portId1), NULL);
#else 
	#define SEND_MSG(gpio_evt_queue_key, portId, portId1)
#endif
	for (int i = 0; i < sizeof(gp_cfg) / sizeof(gpio_cfg); i++) {
		delta = (double)(gpio_get_level(gp_cfg[i].gpio_id) - gp_cfg[i].gp_st[gp_cfg[i].index]) / 10.0;
		uint32_t portId = gp_cfg[i].gpio_id;

		if ((gp_cfg[i].avg > gp_cfg[i].thresh) && ((gp_cfg[i].avg + delta) < gp_cfg[i].thresh)) {
			// 下降沿函数
			//ESP_LOGI("BUTTON","GPIO[%d] name[%s] intr, val: %d\n", gp_cfg[i].gpio_id, GetSwitchName(gp_cfg[i].gpio_id), gpio_get_level(gp_cfg[i].gpio_id));
			uint32_t portId1 = 255;
			if (gp_cfg[i].gpio_id == GPIO_INPUT_IO_ROTATE) {
				SEND_MSG(gpio_evt_queue_key, portId, portId1);
				gpio_flg[portId] = 1;
			} else if (gp_cfg[i].gpio_id == GPIO_INPUT_IO_C) {
				// C 下降沿，如果A为低电平，那就是正转 
				if (gp_cfg[i - 1].avg < gp_cfg[i - 1].thresh) {
					SEND_MSG(gpio_evt_queue_key, portId, portId1);
					gpio_flg[portId] = 1;
				} else {
					portId = gp_cfg[i - 1].gpio_id;
					SEND_MSG(gpio_evt_queue_key, portId, portId1);
					gpio_flg[portId] = 1;
				}
			} else if (gp_cfg[i].gpio_id == GPIO_INPUT_IO_A) {
				;// 默认不处理。没有考虑到此分支，导致异常；
			} else {
				SEND_MSG(gpio_evt_queue_key, portId, portId1);
				gpio_flg[portId] = 1;
			}
		}


		// 刷新数据
		gp_cfg[i].gp_st[gp_cfg[i].index] = gpio_get_level(gp_cfg[i].gpio_id);
		gp_cfg[i].avg = gp_cfg[i].avg + delta;
		gp_cfg[i].index = (gp_cfg[i].index + 1) % 10;
	}


	return;
}
                             
/*
 * Initialize selected timer of the timer group 0
 *
 * timer_idx - the timer number to initialize
 * auto_reload - should the timer auto reload on alarm?
 * timer_interval_sec - the interval of alarm to set
 */
static void start_periodic_timer()
{
    const esp_timer_create_args_t periodic_timer_args = {
            .callback = &gpio_proc,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodic"
    };

    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    /* The timer has been created but is not running yet */
	
	
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 2000)); // 1ms
}


void app_main_gpio()
{
	gpio_config_t io_conf;
	io_conf.intr_type = GPIO_PIN_INTR_NEGEDGE;//interrupt of rising edge
	io_conf.pin_bit_mask = GPIO_INPUT_SWITCHS_SEL;//bit mask of the pins, use GPIO32 here
	io_conf.mode = GPIO_MODE_INPUT;//set as input mode
	io_conf.pull_up_en = 0;//enable pull-up mode
	gpio_config(&io_conf);

	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_UP, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_DOWN, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_LEFT, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_RIGHT, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_OK, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_SELECT, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_A, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_B, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_C, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_SWITCH_D, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(GPIO_INPUT_IO_ROTATE, GPIO_PULLUP_ONLY);
 	ESP_LOGI("app_main_gpio","GPIO[%d]", 0);
	//create a queue to handle gpio event from isr
	gpio_evt_queue_key = xQueueCreate(10, sizeof(uint32_t));
	//xTaskCreate(gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL);

	//install gpio isr service
  	start_periodic_timer();
}

