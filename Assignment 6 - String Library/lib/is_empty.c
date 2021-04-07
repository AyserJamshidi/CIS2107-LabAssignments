/*
 *
 */
#include "../include/personal_string.h"

int is_empty(char *s) {
	if (s != 0)
		while (*s != '\0')
			if (*(s++) != ' ')
				return 0;

	return 1;
}