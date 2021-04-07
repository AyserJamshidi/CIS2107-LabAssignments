/*
 * Returns a new string consisting of all of the letters of s, but padded with spaces at the end so that
 * the total length of the returned string is an even multiple of d. If the length of s is already an even
 * multiple of d, the function returns a copy of s. The function returns NULL on failure or if s is NULL.
 * Otherwise, it returns the new string. It is up to the caller to free any memory allocated by the function.
 */
#include <stdlib.h>
#include "../include/personal_string.h"

int euclidean_alg(int a, int b);

char *pad(char *s, int d) {
	if (s == 0) // s is already
		return 0;

	int s_length = str_len(s);
	int new_arr_length;

	if (s_length % d == 0) // No padding needed.
		new_arr_length = s_length;
	else // Find out how much padding is needed
		new_arr_length = euclidean_alg(s_length, d);

	if (new_arr_length == 1) // There is no GCD between s_length and d when the GCD is 1.
		return 0;

	// This is possible, let's do it!
	char *outputString = malloc(new_arr_length + 1); // Add 1 for null terminator

	for (int i = 0; i < new_arr_length; i++)
		if (i < s_length)
			outputString[i] = s[i];
		else
			outputString[i] = ' ';

	outputString[new_arr_length] = '\0'; // Add null terminator!

	return outputString;
}

int euclidean_alg(int a, int b) {
	if (b == 0)
		return a;

	return euclidean_alg(b, a % b);
}