#include <printf.h>
#include <string.h>
#include <stdlib.h>

/*
 * Design a function which will swap the pointers p and q.
 */
int divisibleByFour(int x);

/*
 * Design a C function, which is passed a C-string s, a C-string sep, an int multiplier m.
 * The function returns a new string which is the original string duplicated m times, separated by sep.
 * For example, if s = “ha”, sep = “ ”, and m=3, the function returns the string “ha ha ha”.
 * The caller is responsible for freeing the memory allocated by your function, so you do not need to worry about doing so inside the function itself.
 */
char *stringDelimDuplicator(char *s, char *sep, int m);

int main() {
	for (int i = 0; i < 100000000; i++) { // 100 million tests
		if (divisibleByFour(i) && i % 4 != 0) {
			printf("Our function said %i was divisible by 4 but it actually isn't!", i);
			exit(-1);
		}
	}

	for (int i = 0; i > -100000000; i--) { // 100 million tests
		if (divisibleByFour(i) && i % 4 != 0) {
			printf("Our function said %i w2s divisible by 4 but it actually isn't!", i);
			exit(-1);
		}
	}

	// stringDelimDuplicator test
	char *sep = ". .";	char *s = "ha";


	printf("%s", stringDelimDuplicator(s, sep, 3));
}

int divisibleByFour(int x) {
	/*
	 * When something is divisible by 4 it will never have 1 in either of its first two bits.
	 *
	 * If we shift 30 times to the left, if the number was divisible by 4, the shifted results would
	 * equal to 0.
	 */
	return x << 30 == 0;
}

char *stringDelimDuplicator(char *s, char *sep, int m) {
	const unsigned int s_len = strlen(s), sep_len = strlen(sep); // Stores the lengths of s and sep in an unchangeable var
	const unsigned int total_len = ((s_len * m) + (sep_len * (m - 1))) + 1; // length of output string + 1 for null terminator
	char *output = malloc(total_len);

	for (unsigned int i = 0, addr_offset = 0; i < m; i++) {
		memcpy(output + addr_offset, s, s_len); // Add the string
		addr_offset += s_len; // Increase the address offset by the added length

		if (i < m - 1) { // Only apply the separator when our increment count is lower than the duplicating amount - 1
			memcpy(output + addr_offset, sep, sep_len); // Same thing as above except with sep
			addr_offset += sep_len;
		}
	}

	output[total_len - 1] = '\0'; // Add null terminator at the end

	return output;
}