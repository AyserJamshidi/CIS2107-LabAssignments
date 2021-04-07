cmake_minimum_required(VERSION 3.17)
project(Assignment-6 C)

set(CMAKE_C_STANDARD 11)

add_executable(
	Assignment-6 

	string_driver.c 
	include/personal_string.h 
	lib/str_len.c 
	lib/all_letters.c 
	lib/num_in_range.c 
	lib/diff_TODO.c 
	lib/shorten.c 
	lib/len_diff.c 
	lib/rm_left_space.c 
	lib/rm_right_space.c 
	lib/rm_space.c 
	lib/find.c 
	lib/ptr_to.c 
	lib/is_empty.c 
	lib/str_zip.c
        lib/capitalize.c lib/strcmp_ign_case_TODO.c lib/take_last.c lib/dedup.c lib/pad.c)