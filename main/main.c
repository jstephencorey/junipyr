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

    esp_vfs_spiffs_register(&conf);
    ESP_LOGD(TAG, "Initializing spiffs");
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
