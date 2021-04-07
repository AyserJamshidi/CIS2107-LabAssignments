#include "../include/personal_string.h"

/*
 * Removes whitespace characters from the beginning and the ending s
 */
void rm_space(char *s) {
	rm_left_space(s);
	rm_right_space(s);
}