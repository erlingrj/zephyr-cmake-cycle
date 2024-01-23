cmake_minimum_required(VERSION 3.19)
# This is the default conf file.
set(CONF_FILE prj_lf.conf)


# Including this second conf file causes a CMake cycle. Comment it out
# and it will work.
set(OVERLAY_CONFIG prj.conf)

# Selecting board specified in target property
set(BOARD esp32)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE} 3.4.0)

project(Main LANGUAGES C)

# Build library which depends on Zephyr
add_subdirectory(core)

# Declare a new executable target and list all its sources
target_sources(app PRIVATE Main.c)

target_link_libraries(app PRIVATE core)