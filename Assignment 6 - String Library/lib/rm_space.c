/*
 * Removes whitespace characters from the beginning and the ending s
 */
#include "../include/personal_string.h"

void rm_space(char *s) {
	rm_left_space(s);
	rm_right_space(s);
}