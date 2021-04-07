/*
 * Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged
 */
#include "../include/personal_string.h"

void shorten(char *s, int new_len) {
	if (str_len(s) <= new_len) // If the length of the c string is less than or equal to new_len, do nothing
		return;

	s[new_len] = '\0'; // Relocate the null terminator

	// replacing old chars with 0 bytes.  Is this even necessary?
//	for (int i = new_len + 1; i < s_length; i++) {
//		s[i] = 0;
//	}
}