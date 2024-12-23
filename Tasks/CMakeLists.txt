cmake_minimum_required(VERSION 3.22)
project(LR7)


add_library(String STATIC func.cpp)

add_executable(main Tasks.cpp)
add_executable(main_Asan Tasks.cpp)
add_executable(main_Tsan Tasks.cpp)

target_compile_options(main_Asan PRIVATE -fsanitize=address)
target_compile_options(main_Tsan PRIVATE -fsanitize=thread)
target_link_options(main_Asan PRIVATE -fsanitize=address)
target_link_options(main_Tsan PRIVATE -fsanitize=thread)

target_link_libraries(main String)
target_link_libraries(main_Asan String)
target_link_libraries(main_Tsan String)

enable_testing()