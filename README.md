This is a repository based off of https://github.com/DaveBben/esp32-llm, the goal of which is to run a performant and capable language model off of the esp-32. 

A lot of the inspiration and changes were taken from that repo, and the main code to run it was taken from this repo: https://github.com/karpathy/llama2.c


To run:
    idf.py set-target esp32
    idf.py build
    python -m esptool --chip esp32s3 -b 460800 --before default_reset --after hard_reset write_flash --flash_mode dio --flash_size 2MB --flash_freq 80m 0x0 build\bootloader\bootloader.bin 0x8000 build\partition_table\partition-table.bin 0x10000 build\junipyr.bin

To monitor:
    python %IDF_PATH%\tools\idf_monitor.py -b 460800

Note: both of these will detect the port automatically, though you probably need just one esp32 plugged in at a time. 