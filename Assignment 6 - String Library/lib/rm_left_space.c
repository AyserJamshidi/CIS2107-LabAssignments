#include "../include/personal_string.h"

/*
 * Removes whitespace characters from the beginning of s
 */
void rm_left_space(char *s) {
	int shift_amount = 0;  // Will contain the amount of left shifts we need to do

	// Stores the amount of starting white spaces into shiftCount
	while (*(s + shift_amount) == ' ')
		shift_amount++;

	if (shift_amount != 0) { // If we should shift
		int loop_amount = str_len(s) - shift_amount; // c string's length - shiftCount

		// Shift every (i + shiftCount)'th char to the left shiftCount amount
		for (int i = 0; i < loop_amount; i++)
			*(s + i) = *(s + i + shift_amount);

		*(s + loop_amount) = '\0'; // Reapply a null terminator to the new ending of the c string
	}
}