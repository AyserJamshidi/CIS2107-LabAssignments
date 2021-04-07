/*
 * Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.
 */
#include "../include/personal_string.h"

void capitalize(char *s) {
	int previousWasSpace = 1;

	while (*s != '\0') { // Keep going until null terminator is hit
		if (previousWasSpace) {
			if (97 <= *s && *s <= 122) // If we're at a lowercase ASCII letter
				*s -= 32; // Subtract 32d so we can convert lowercase ASCII to uppercase.

			previousWasSpace = 0;
		} else { // Previous was NOT a space, we need to ensure everything else is lowercase
			if (*s == ' ') // We're at a space, toggle bool
				previousWasSpace = 1;
			else {
				if (65 <= *s && *s <= 90) { // If we're at an uppercase ASCII letter
					*s += 32; // Add 32d so we can convert uppercase ASCII to lowercase.
				}
			}
		}

		s++; // increase offset
	}
}