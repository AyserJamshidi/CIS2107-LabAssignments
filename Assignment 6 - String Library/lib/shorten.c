#include "../include/personal_string.h"

/*
 * Shortens the string s to new_len. If the original length
 * of s is less than or equal to new_len, s is unchanged
 */
void shorten(char *s, int new_len) {
	if (str_len(s) > new_len)  // If the length of the c string is less than or equal to new_len, do nothing
		s[new_len] = '\0';  // Relocate the null terminator
}