/*
 * Removes whitespace characters from the beginning of s
 */
#include <printf.h>
#include "../include/personal_string.h"

void rm_left_space(char *s) {
	int shiftCount = 0;

	while (*(s + shiftCount) == ' ')
		shiftCount++;

	int s_len = str_len(s);

	for (int i = 0; i < s_len - shiftCount; i++)
		s[i] = s[i + shiftCount];

	s[s_len - shiftCount] = '\0'; // Apply null terminator at the end of the shifted string
}