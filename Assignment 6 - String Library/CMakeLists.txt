cmake_minimum_required(VERSION 3.17)
project(Assignment-6 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment-6 string_driver.c include/personal_string.h lib/str_len.c lib/all_letters.c lib/num_in_range.c lib/diff_TODO.c lib/shorten.c lib/len_diff.c lib/rm_left_space.c)