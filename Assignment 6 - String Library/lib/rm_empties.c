#include "../include/personal_string.h"

/*
 * Words is an array of string terminated with a NULL pointer.
 *
 * The function removes any empty strings (i.e., strings of length 0)
 * from the array.
 */
void rm_empties(char **words) {
	for (int i = 0; words[i] != 0; i++) // Loop every c string
		if (str_len(words[i]) == 0) // If our current c string's length is 0
			for (int j = i;;j++) // Loop infinitely until we've hit the array's null terminator
				if ((words[j] = words[j + 1]) == '\0') // Shift everything after this element left once until we've shifted null terminator
					break;
}