#include "../include/personal_string.h"

/*
 * Returns the number of characters c in s1 such that b<=c<=t
 */
int num_in_range(char *s1, char b, char t) {
	int output_num = 0;

	while (*s1 != '\0') { // While we haven't hit a null terminator
		if (b <= *s1 && *s1 <= t) // If the current char is in the bounds [b, t]
			output_num++; // Increment the output value;

		s1++; // Increment the address by an offset of 1 byte (the size of a char)
	}

	return output_num;
}