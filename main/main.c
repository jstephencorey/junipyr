#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "MAIN";


void app_main(void)
{
    ESP_LOGI(TAG, "Starting !");
    printf("Hello, ESP32!\n");

    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("Tick\n");
    }
}
