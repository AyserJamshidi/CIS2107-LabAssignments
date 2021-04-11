#include "../include/personal_string.h"

#include "stdlib.h"
#include <stdio.h>

/*
 * Returns the number of positions in which s1 and s2 differ, i.e.,
 * it returns the number of changes that would need to be made in order
 * to transform s1 into s2, where a change could be a character
 * substitution, an insertion, or a deletion.
*/
int diff(char *s1, char *s2) {
	int s1_length = str_len(s1), s2_length = str_len(s2);
	int substitution = 0, insertion = 0, deletions = abs(s1_length - s2_length);
	printf("\nPredicted deletions before loop: %i", deletions);
	// Scan for deletions
	for (int i = 0; i < s1_length; i++) {
		int should_del = 1;
		for (int j = i; j < s2_length; j++) {
			if (s1[i] == s2[j]) {
//				if (s1[])
				should_del = 0;
				break;
			}
		}

		if (should_del)
			deletions++;
	}

	printf("\nDeletions: %i", deletions);
}