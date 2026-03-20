cmake_minimum_required(VERSION 3.20)
project(revisao_c C)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(HAS_FLOAT "Float support enabled" ON)

add_executable(main main.c)

if(HAS_FLOAT)
    target_compile_definitions(main PRIVATE HAS_FLOAT)
endif()

target_sources(main PRIVATE
  number.c
)
