idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ".")

# in a component's CMakeLists.txt file
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLOG_LOCAL_LEVEL=ESP_LOG_VERBOSE") # https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/log.html


# Create a SPIFFS image from the contents of the 'spiffs_image' directory
# that fits the partition named 'data'. FLASH_IN_PROJECT indicates that
# the generated image should be flashed when the entire project is flashed to
# the target with 'idf.py -p PORT flash'.
spiffs_create_partition_image(data ../data FLASH_IN_PROJECT)