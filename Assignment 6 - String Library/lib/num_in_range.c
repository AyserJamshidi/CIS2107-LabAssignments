#include "../include/personal_string.h"

/*
 * Returns the number of characters c in s1 such that b<=c<=t
 */
int num_in_range(char *s1, char b, char t) {
	int amount_in_range = 0; // Amount of c in b<=c<=t

	while (*s1 != '\0') { // While we haven't hit a null terminator
		if (b <= *s1 && *s1 <= t) // If the current char is in the bounds [b, t]
			amount_in_range++; // Increment the output value;

		s1++; // Increment the address by an offset of 1 byte (the size of a char)
	}

	return amount_in_range;
}