#include <stdlib.h>

#include "../include/personal_string.h"

int array_contains_char(char *s, char c);

/*
 * Returns a new string based on s, but without any duplicate characters.
 * For example, if s is the string, "There's always money in the banana
 * stand.", the function returns the string "Ther's alwymonitbd.".
 *
 * It is up to the caller to free the memory allocated by the function.
 */
char *dedup(char *s) {
	char ordered_container[str_len(s)]; // Temporary char array used as a container
	int container_index = 0;  // Index and amount of chars in orderedContainer

	// Put all unique chars in orderedContainer from left to right
	while (*s != '\0') {
		if (!array_contains_char(ordered_container, *s)) // If ordered_container doesn't contain the first char of s
			ordered_container[container_index++] = *s; // Increment container index for future use

		s++;
	}

	// Use container_index as a malloc size indicator
	char *output_string = malloc(container_index + 1);  // Assign space for the c string

	for (int i = 0; i < container_index; i++) // Place all chars in properly sized output c string
		output_string[i] = ordered_container[i];

	output_string[container_index] = '\0'; // Apply null terminator to the end of the array

	return output_string; // Return properly sized c string
}

int array_contains_char(char *s, char c) {
	while (*s != '\0') {  // While we're not at the end of the array
		if (*s == c)      // If the current character is the character we're looking for
			return 1;

		s++;
	}

	return 0;  // c was not found in the c string.
}