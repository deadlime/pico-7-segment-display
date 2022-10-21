add_executable(basic_pio basic_pio.c)
pico_generate_pio_header(basic_pio ${CMAKE_CURRENT_LIST_DIR}/basic_pio.pio)
target_link_libraries(basic_pio pico_stdlib hardware_pio)
pico_add_extra_outputs(basic_pio)
