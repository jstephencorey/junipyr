#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_spiffs.h"

static const char *TAG = "MAIN";


void setup_spiffs() {
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/data",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = true
    };

    // esp_vfs_spiffs_register(&conf);
    ESP_LOGD(TAG, "Initializing spiffs");
    esp_err_t ret = esp_vfs_spiffs_register(&conf); // verification code copied from https://github.com/DaveBben/esp32-llm

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        }
        else if (ret == ESP_ERR_NOT_FOUND)
        {
            ESP_LOGE(TAG, "Failed to find SPIFFS partition");
        }
        else
        {
            ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    }

    size_t total = 0, used = 0;
    ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
    }
    else
    {
        ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    }
}

void test_spiffs() {
    FILE* f = fopen("/data/hello.txt", "r");
    if (f) {
        char line[64];
        fgets(line, sizeof(line), f);
        fclose(f);
        printf("Read from file: '%s'\n", line);
    } else {
        printf("Failed to open file\n");
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "Starting !");
    printf("Hello, ESP32!\n");

    setup_spiffs();
    test_spiffs();

    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("Tick\n");
    }
}
