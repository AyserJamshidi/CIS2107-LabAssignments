#include <stdlib.h>

#include "../include/personal_string.h"

/*
 * Returns a new string consisting of all of the letters of s, but padded with spaces at the end so that
 * the total length of the returned string is an even multiple of d. If the length of s is already an even
 * multiple of d, the function returns a copy of s. The function returns NULL on failure or if s is NULL.
 * Otherwise, it returns the new string. It is up to the caller to free any memory allocated by the function.
 */
char *pad(char *s, int d) {
	if (s == 0)  // The function returns NULL if s is NULL
		return 0;

	int s_length = str_len(s);
	int new_arr_length = s_length;

	if (s_length % d != 0)  // Padding is needed if length isn't a multiple of d.
		new_arr_length *= d; // Pad by doing length * d

	char *output_string = malloc(new_arr_length + 1);  // Add 1 for null terminator

	for (int i = 0; i < new_arr_length; i++)
		output_string[i] = (i < s_length) ? s[i] : ' ';

	output_string[new_arr_length] = '\0';  // Add null terminator!

	return output_string;
}