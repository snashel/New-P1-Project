
add_library(functions functions.c)
target_include_directories(functions PUBLIC .)

add_executable(main main.c)
target_link_libraries(main functions)

