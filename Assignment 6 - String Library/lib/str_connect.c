#include "../include/personal_string.h"

#include <stdlib.h>

/*
 * Returns a string consisting of the first n strings in strs with
 * the character c used as a separator. For example, if strs contains
 * the strings {"Washington", "Adams", "Jefferson"} and c is '+', the
 * function returns the string "Washington+Adams+Jefferson"
 */
char *str_connect(char **strs, int n, char c) {
	int length_of_chars = 0;

	for (int i = 0; i < n; i++) // Store the amount of chars we'll be storing into the output c string
		length_of_chars += str_len(strs[i]);

	char *output_string = (char *) malloc(length_of_chars + n);
	char *original_output_string = output_string;

	for (int i = 0; i < n; i++) { // Loop n amount of c strings
		int cur_word_length = str_len(strs[i]); // Store the current word's length

		for (int j = 0; j < cur_word_length; j++) // Assign the current word's letter to our output c string's address
			*output_string++ = *strs[i]++;

		if (i != n - 1) // Don't place the separator if we're done looping
			*output_string++ = c;
	}
	*output_string = '\0'; // Place a null terminator at the end of the c string

	return original_output_string;
}