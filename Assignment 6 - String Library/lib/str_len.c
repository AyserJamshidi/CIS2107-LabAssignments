/*
 * Returns the number of characters in the string s (up to but not including the '\0' character).
 */
#include "../include/personal_string.h"

int str_len(char *s) {
	char *curAddress = s; // Set to first char mem location

	while (*curAddress != '\0') // While we haven't hit a null terminator
		curAddress++; // Increment the address by an offset of 1 byte (the size of a char)

	// When we're done looping, the length of the string will be the offset length, so we do (curAddress - s) to get the offset
	return curAddress - s;
}