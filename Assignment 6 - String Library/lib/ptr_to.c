#include "../include/personal_string.h"

/*
 * Returns a pointer to the first occurrence of n in the string h or NULL if it isn't found
 */
char *ptr_to(char *h, char *n) {
	int n_length = str_len(n);

	for (int i = 0; i < str_len(h) - n_length + 1; i++) { // Loop h - n length + 1 as anything past this is impossible to have the sequence
		int foundFirst = 1;

		for (int j = 0; j < n_length; j++) // Loop through every character in the c string n and start comparing
			if (n[j] != h[i + j]) { // If we found a part of the sequence that doesn't match,
				foundFirst = 0;
				break;
			}

		if (foundFirst)
			return h + i; // Return base address + offset
	}

	return 0;
}