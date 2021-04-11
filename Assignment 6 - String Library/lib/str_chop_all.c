#include "../include/personal_string.h"

#include "stdlib.h"

/*
 * Returns an array of string consisting of the characters in s split
 * into tokens based on the delimeter c, followed by a NULL pointer.
 *
 * For example, if s is "I am ready for a nice vacation" and c is ' ',
 * it returns {"I", "am", "ready", "for", "a", "nice", "vacation", NULL}
 */
char **str_chop_all(char *s, char c) {
	char *original_s_ptr = s; // Store the original pointer to s as we'll be incrementing s later

	// New array always starts at 1 because of the array's null terminator
	int new_arr_size = 1, max_word_length = 0, word_len_container = 0;

	// Loop through the c string and find out the biggest word length and how big our array should be
	while (*s != '\0') {
		if (++word_len_container > max_word_length)
			max_word_length = word_len_container;

		if (*s++ == c)
			new_arr_size++, word_len_container = 0;
	}
	s = original_s_ptr;

	int word_index = 0, letter_index = 0;
	char **output_arr = malloc(sizeof(char *) * new_arr_size); // Store (8 * new_arr_size) amount of char* pointers
	output_arr[word_index] = malloc(sizeof(char) * max_word_length); // Initialize the first c string

	while (*s != '\0') {
		if (*s == c) { // C string current char is the delimiter
			output_arr[word_index][letter_index] = '\0';
			word_index++, letter_index = 0;

			if (word_index != new_arr_size)
				output_arr[word_index] = malloc(sizeof(char) * max_word_length); // Create a new word at index word_index
		} else {
			output_arr[word_index][letter_index++] = *s;
		}

		s++;
	}
	output_arr[word_index][letter_index] = '\0'; // Add a null terminator to the last word we were adding
	output_arr[word_index + 1] = 0; // Null pointer as the last array element

	return output_arr;
}