#include "../include/personal_string.h"
#include <stdlib.h>

/*
 * Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other.
 * For example, if s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob"
 */
char *str_zip(char *s1, char *s2) {
	int s1_length = str_len(s1), s2_length = str_len(s2);
	int both_length = s1_length + s2_length;
	char *zipped = malloc(both_length);

	int index = 0, s1_index = 0, s2_index = 0;

	while (s1_length || s2_length) {
		if (s1_length)
			zipped[index++] = s1[s1_length--, s1_index++];

		if (s2_length)
			zipped[index++] = s2[s2_length--, s2_index++];
	}

	zipped[both_length] = '\0';

	return zipped;
}