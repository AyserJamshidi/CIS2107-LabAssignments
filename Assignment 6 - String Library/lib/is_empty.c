#include "../include/personal_string.h"

/*
 * Returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.
 */
int is_empty(char *s) {
	if (s != 0) // Returns 1 if s is null
		while (*s != '\0') // While we're not at the end of the C string
			if (*(s++) != ' ') // Compare if s is not a white space and increment s
				return 0; // We found a character that isn't a white space.

	return 1;
}