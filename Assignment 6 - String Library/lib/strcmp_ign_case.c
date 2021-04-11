#include "../include/personal_string.h"

/*
 * Compares s1 and s2 ignoring case. Returns a positive number if s1
 * would appear after s2 in the dictionary, a negative number if it
 * would appear before s2, or 0 if the two are equal.
 */
signed int strcmp_ign_case(char *s1, char *s2) {
	signed int return_val;

	while (*s1 != '\0' && s2 != '\0') { // If we're not at the end of the suffix
		if (*s1 != *s2) {
			if (('A' <= *s1 && *s1 <= 'Z') && ('a' <= *s2 && *s2 <= 'z')) // s1 is upper, s2 is lower
				return_val = *s1 + 32 - *s2;
			else if (('a' <= *s1 && *s1 <= 'z') && ('A' <= *s2 && *s2 <= 'Z')) // s1 is lower, s2 is upper
				return_val = *s1 - 32 - *s2;
			else // s1 and s2 are either both the same casing, or a weird char.  Just return their difference.
				return_val = *s1 - *s2;

			if (return_val != 0) // s2 comes first in the dictionary
				return return_val;
		}

		s1++, s2++; // Increment both c strings to their next char as we haven't found any mismatches yet
	}

	return 0; // Everything was the same, ignoring their casing!
}