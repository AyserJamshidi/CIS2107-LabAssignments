#include <stdlib.h>
#include "../include/personal_string.h"

int array_contains_char(char *s, char c);

/*
 * Returns a new string based on s, but without any duplicate characters. For example, if s is the string,
 * "There's always money in the banana stand.", the function returns the string "Ther's alwymonitbd.".
 * It is up to the caller to free the memory allocated by the function.
 */
char *dedup(char *s) {
	char orderedContainer[str_len(s)];
	int amountInContainer = 0; // Index and amount of chars in orderedContainer

	// Put all unique chars in orderedContainer from left to right
	while (*s != '\0') {
		if (!array_contains_char(orderedContainer, *s))
			orderedContainer[amountInContainer++] = *s;

		s++;
	}

	char *outputString = malloc(amountInContainer + 1); // Assign space for the c string

	for (int i = 0; i < amountInContainer; i++) // Place all chars in properly sized output c string
		outputString[i] = orderedContainer[i];

	outputString[amountInContainer] = '\0'; // Apply null terminator to the end of the array

	// Return properly sized c string
	return outputString;
}

int array_contains_char(char *s, char c) {
	while (*s != '\0') { // While we're not at the end of the array
		if (*s == c) // If the current character is the character we're looking for
			return 1;

		s++;
	}

	return 0; // c was not found in the c string.
}