#include <stdlib.h>
#include "../include/personal_string.h"

/*
 * Returns a new string consisting of all of the characters of s1
 * and s2 interleaved with each other. For example, if s1 is
 * "Spongebob" and s2 is "Patrick", the function returns the string
 * "SPpaotnrgiecbkob"
 */
char *str_zip(char *s1, char *s2) {
	int s1_length = str_len(s1), s2_length = str_len(s2); // Get both c string lengths
	char *zipped = malloc(s1_length + s2_length); // Allocate space for the new c string

	int index = 0, s1_index = 0, s2_index = 0; // Individual indexes for zipped, s1 and s2

	while (s1_length || s2_length) { // While s1 or s2 have chars left
		if (s1_length) // If s1 has chars left, add it then shift indexes
			zipped[index++] = s1[s1_length--, s1_index++]; // We add to zipped and s1_index and remove from s1 len

		if (s2_length) // Same process as above
			zipped[index++] = s2[s2_length--, s2_index++];
	}

	zipped[s1_index + s2_index] = '\0'; // Add null terminator at the end

	return zipped;
}