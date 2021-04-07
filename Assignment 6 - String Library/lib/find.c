#include "../include/personal_string.h"

/*
 * Returns the index of the first occurrence of n in the string h or -1 if it isn't found.
 */
int find(char *h, char *n) {
	int n_length = str_len(n), sequences = 0;

	for (int i = 0; i < str_len(h) - n_length + 1; i++) { // Loop h - n length + 1 as anything past this is impossible to have the sequence
		int canAdd = 1;

		for (int j = 0; j < n_length; j++) // Loop through every character in the c string n and start comparing
			if (n[j] != h[i + j]) { // If we found a part of the sequence that doesn't match,
				canAdd = 0; // Don't add it!
				break;
			}

		if (canAdd)
			sequences++;
	}

	return sequences;
}