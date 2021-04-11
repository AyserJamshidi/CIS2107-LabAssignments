#include "../include/personal_string.h"

/*
 * Returns 1 if suff is a suffix of s ignoring case or 0 otherwise.
 */
int ends_with_ignore_case(char *s, char *suff) {
	int s_length = str_len(s), suff_length = str_len(suff);

	if (s_length < suff_length) // Return 0 if it's impossible for s to have suff in it
		return 0;

	// (s + s_length - suff_length) is our beginning character.
	// If str_cmp_ign_care returns 0, it means they are the same, so we then return 1
	return strcmp_ign_case(s + s_length - suff_length, suff) == 0;
}