#include "../include/personal_string.h"

/*
 * Changes s so that the first letter of every word is in upper case
 * and each additional letter is in lower case.
 */
void capitalize(char *s) {
	int prev_was_space = 1; // Boolean

	while (*s != '\0') { // Keep going until null terminator is hit
		if (*s == ' ') // We're at a space, do nothing except toggle the boolean
			prev_was_space = 1;
		else if (('A' <= *s && *s <= 'Z') || ('a' <= *s && *s <= 'z')) { // We're at a letter, let's see what we need to do
			int is_uppercase = 'A' <= *s && *s <= 'Z';

			if (prev_was_space) { // Everything should be uppercase
				if (!is_uppercase) // Subtract 32d if it's a lowercase letter
					*s -= 32;
			} else if (is_uppercase) // Everything should be lowercase, add 32d if it's an uppercase letter
				*s += 32;

			prev_was_space = 0; // Set to 0 since this is a letter
		}

		s++; // increase offset
	}
}