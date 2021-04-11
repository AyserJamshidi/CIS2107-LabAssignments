#include "../include/personal_string.h"

/*
 * Returns a pointer to the first occurrence of n in the string h
 * or NULL if it isn't found
 */
char *ptr_to(char *h, char *n) {
	int char_offset = find(h, n); // Store the index of the first occurrence of n

	// If char_offset is -1, return a null pointer, otherwise, return h + char_offset
	return char_offset == -1 ? 0 : (h + char_offset);
}