#include "../include/personal_string.h"

/*
 * Returns the index of the first occurrence of n in the string h
 * or -1 if it isn't found.
 */
int find(char *h, char *n) {
	char *original_h = h; // Store the original pointer of h as we'll be incrementing it later
	int n_length = str_len(n);

	while (*h != '\0') { // While h still has chars left
		int is_same = 1; // Set to true by default as it'll be changed later

		for (int i = 0; i < n_length; i++) // Loop every char in n
			if (*(h + i) != *(n + i)) { // If the current h char != current n char
				is_same = 0; // Set to false and break out of for loop to avoid useless comparisons
				break;
			}

		if (is_same) // If isSame turns out to be true
			return h - original_h; // Return the index

		h++; // increment h as we still need to scan
	}

	return 0; // If we hit a null terminator in h, we never found n in h
}