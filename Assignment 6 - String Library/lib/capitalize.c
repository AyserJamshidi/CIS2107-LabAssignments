#include "../include/personal_string.h"

/*
 * Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.
 */
void capitalize(char *s) {
	int previousWasSpace = 1; // Boolean

	while (*s != '\0') { // Keep going until null terminator is hit
		if (*s == ' ') // We're at a space, do nothing except toggle the boolean
			previousWasSpace = 1;
		else if ((65 <= *s && *s <= 90) || (97 <= *s && *s <= 122)) { // We're at a letter, let's see what we need to do
			int isUpperCase = 65 <= *s && *s <= 90;

			if (previousWasSpace) { // Everything should be uppercase
				if (!isUpperCase) // Subtract 32d if it's a lowercase letter
					*s -= 32;
			} else // Everything should be lowercase
				if (isUpperCase) // Add 32d if it's an uppercase letter
					*s += 32;

			previousWasSpace = 0; // Set to 0 since this is a letter
		}

		s++; // increase offset
	}
}