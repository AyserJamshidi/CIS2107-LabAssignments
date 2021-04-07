#include <stdio.h>

unsigned int add(unsigned int, unsigned int);

unsigned int sub(unsigned int, unsigned int);

unsigned int mul(unsigned int, unsigned int);

unsigned int lt(unsigned int, unsigned int);

unsigned int gt(unsigned int, unsigned int);

unsigned int getByte(unsigned int, unsigned int);

int main(int argc, char **argv) {

	unsigned int i, j;

//	i = 1000, j = 2;
	printf("Enter any integer >= 0... ");

	scanf("%u", &i);
	printf("\nEnter another integer >= 0... ");
	scanf("%u", &j);
	printf("\ni = %i and j = %i", i, j);
	printf("\ni + j = %u", add(i, j));
	printf("\ni - j = %u", sub(i, j));
	printf("\ni * j = %u", mul(i, j));
	printf("\ni > j = %s", (gt(i, j) ? "TRUE" : "FALSE"));
	printf("\ni < j = %s", (lt(i, j) ? "TRUE" : "FALSE"));
	printf("\njth byte of i = %ux\n", getByte(i, j));

	return 0;
}

/*
 * & = AND 			= When both have a 1
 * | = OR 			= When either have a 1
 * ^ = XOR 			= When only one or the other have a 1
 * ~ = NOT/NOR 		=
 * << = Left Shift 	= Shifts all bits to the left one time.
 * >> = Right Shift	= Shifts all bits to the right one time.
 */

/* can be done in a total of 7 lines, including one to declare an unsigned int, */
/* two for a while loop, and one for the return */
unsigned int add(unsigned int i, unsigned int j) {
	while (i != 0) { // We are using i as our carry container
		unsigned int carryPositions = i & j; // bit positions of where we should carry over a 1 (Step 1)
		j ^= i; // Actual addition (Step 2)
		i = carryPositions << 1; // Set i equal to the amount we should carry before we did the xor adding
	}

	return j;
}

unsigned int sub(unsigned int i, unsigned int j) {
	return add(i, add(~j, 1)); // We add 1 to the NOR of j as it will always be 1 lower than the opposite sign of itself
}

unsigned int mul(unsigned int i, unsigned int j) {
/* can be done in a total of 8 lines including one to declare unsigned ints */
/* two for a for loop, and one for the return */
	if (i == 0 || j == 0) // Multiplying anything by 0 makes the result 0.
		return 0;

	/*
	 * We add iCopy (the original number of i) to i, j amount of times. Basic math principles.
	 */
	for (unsigned int iCopy = i, addedAmount = 1; (addedAmount != j); (addedAmount = add(addedAmount, 1)))
		i = add(i, iCopy);

	return i;
}

/* returns non-zero if i is less than j or zero otherwise */
unsigned int lt(unsigned int i, unsigned int j) {
	if (i == j) // If they are the same they can't be lt or gt
		return 0;

	/*
	 * Loops infinitely until either j or i are 0 then returns 1 if i is 0 before j, otherwise 0
	 * Since these are non-negative numbers then 0 is the lowest bound to check.
	 */
	for (;;) {
		if (i == 0 && j != 0)
			return 1;

		if (j == 0)
			return 0;

		i = sub(i, 1);
		j = sub(j, 1);
	}
}

/* returns non-zero if i is greater than j or zero otherwise */
unsigned int gt(unsigned int i, unsigned int j) {
	if (i == j) // If they are the same they can't be lt or gt
		return 0;

	return !lt(i, j); // If it's not less, then it must be greater
}

/* returns the jth byte of i */
unsigned int getByte(unsigned int i, unsigned int j) {
	if (lt(j, 1) || gt(j, 4)) // Since unsigned bits only have 4 bytes, anything not in [1, 4] returns 0
		return 0;

	/*
	 * unsigned ints are 4 bytes, so 4 * 8 = 32 bits long.
	 *
	 * We can shift left (4 - j) bytes to clean the left side, then right (4 - j) bytes to
	 * go back to its original position, then shift right (j - 1) times to push it to the first byte position
	 *
	 * Left shift amount: (4 - j) * 8 bits
	 * Right shift amount: (j - 1) * 8 bits
	 */
	unsigned int leftShiftAmount = sub(4, j), rightShiftAmount = sub(j, 1); // Set our shift amounts

	i = i << mul(leftShiftAmount, 8); // Shift left by leftAmount
	return i >> mul(add(leftShiftAmount, rightShiftAmount), 8); // Shift right by leftAmount + rightAmount

//	return (i >> mul(8, j)) & 0xFF;
}