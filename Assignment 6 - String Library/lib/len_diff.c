#include "../include/personal_string.h"

/*
 * Returns the length of s1 - the length of s2
 */
int len_diff(char *s1, char *s2) {
	return str_len(s1) - str_len(s2);
}