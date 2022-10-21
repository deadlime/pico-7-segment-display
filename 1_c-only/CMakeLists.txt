add_executable(c_only c_only.c)
target_link_libraries(c_only pico_stdlib)
pico_add_extra_outputs(c_only)
