#include <stdlib.h>

#include "../include/personal_string.h"

/*
 * Returns a new string consisting of the characters in s repeated x times,
 * with the character sep in between.
 *
 * For example, if s is the string all right, * x is 3, and sep is ,
 * the function returns the new string all right,all right,all right.
 *
 * If s is NULL, the function returns NULL.
 *
 * It is up to the caller to free any memory allocated by the function.
 */
char *repeat(char *s, int x, char sep) {
	if (s == 0) // If s is null, we return null
		return 0;

	// (Length of the string + length of the separator) * Repeat amount
	int s_length = str_len(s), new_str_length = (s_length + 1) * x;
	char *repeated_str = malloc(new_str_length); // Allocate new_str_length amount of bytes for our new c string

	// Contains the pointers to the original values of both pointers as we'll be incrementing their address value
	char *original_s = s;
	char *original_repeated_str = repeated_str;

	for (int i = 0; i < x; i++) { // Loop x amount of times
		while (*(s) != '\0') // If we're not at the null terminator
			*repeated_str++ = *s++; // Add the current char from s to repeated_str

		if (i < x - 1) { // If we're not at the last loop
			*repeated_str++ = sep; // Add the separator
			s = original_s; // Reset s pointer so we can add it again in the next loop
		}
	}

	*repeated_str = '\0'; // Place null terminator as the last char

	return original_repeated_str;
}