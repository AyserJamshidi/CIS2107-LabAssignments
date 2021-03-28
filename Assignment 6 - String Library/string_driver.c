#include <stdio.h>
#include "include/personal_string.h"

int main() {
	printf("str_len: %i", str_len("Helloo")); // Expect 6 because there are 6 chars in the string.
	printf("\nall_letters: %i", all_letters("Helloo")); // Expect 1 because this consists only of letters.
	printf("\nnum_in_range: %i", num_in_range("Helloo", 'a', 'l')); // Expect 3 because H is uppercase.

//	printf("\ndiff: %i");

}