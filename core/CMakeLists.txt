add_library(core test.c)
target_link_libraries(core PRIVATE zephyr_interface)
target_link_libraries(core PRIVATE kernel)