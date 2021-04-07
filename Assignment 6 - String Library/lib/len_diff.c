/*
 * Returns the length of s1 - the length of s2
 */
#include "../include/personal_string.h"

int len_diff(char *s1, char *s2) {
	return str_len(s1) - str_len(s2);
}