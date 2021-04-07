/*
 * Returns 1 if all of the characters in the string are either upper-case or lower-case letters of the alphabet. It returns 0 otherwise.
 */
#include "../include/personal_string.h"

int all_letters(char *s) {
	while (*s != '\0') { // While we haven't hit a null terminator
		if (!('a' <= *s && *s <= 'z') || !('A' <= *s && *s <= 'Z')) // If the current char is NOT a lower/uppercase letter of the alphabet
			return 0;

		s++; // Increment the address by an offset of 1 byte (the size of a char)
	}

	return 1;
}