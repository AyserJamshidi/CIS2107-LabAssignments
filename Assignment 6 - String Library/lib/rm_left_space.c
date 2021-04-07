#include "../include/personal_string.h"

/*
 * Removes whitespace characters from the beginning of s
 */
void rm_left_space(char *s) {
	int shiftCount = 0; // Contains the amount of left shifts we need to do

	while (*(s + shiftCount) == ' ') // Stores the amount of starting white spaces into shiftCount
		shiftCount++;

	for (int i = 0; i < str_len(s) + 1 - shiftCount; i++) // Loop string length + 1 - left shift count amount of times
		s[i] = s[i + shiftCount]; // Shifts everything after the shiftCount, left, shiftCount amount of times
}