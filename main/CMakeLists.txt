idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ".")

# in a component's CMakeLists.txt file
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLOG_LOCAL_LEVEL=ESP_LOG_VERBOSE") # https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/log.html