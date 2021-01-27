#include <stdio.h>

#define LEN_A 10

/* function declarations */
void print_array(int[], int);

void reverse(int[], int);

int secondLargest(int A[], int length);

double average(int[], int);

void insert(int[], int, int, int);

int less_than_average(int[], int);

void rotate_right(int[], int, int);

void array_copy(int[], int[], int);

void initialize(int[], int, int);

void evens_on_left(int[], int);

int find(int A[], int len, int x);

int find_last(int A[], int len, int x);

int contains_dup(int A[], int len);

int main(int argc, char **argv) {
	int A[] = {9, 505, 321, 117, 27, 64, 13, 9, 12, 208};
	int B[LEN_A + 1];
	int newValue = 505;
	printf("\nSecond largest is %i\n", secondLargest(A, LEN_A));

	printf("A[] is: ");
	print_array(A, LEN_A); // Expect: (9, 505, 321, 117, 27, 64, 13, 9, 12, 208)

	initialize(B, LEN_A + 1, 0);
	printf("\nB[] is: ");
	print_array(B, LEN_A + 1); // Expect: (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

	array_copy(B, A, LEN_A);
	printf("\nbut now it's ");
	print_array(B, LEN_A + 1); // Expect (9, 505, 321, 117, 27, 64, 13, 9, 12, 208, 0)

	insert(B, newValue, 0, LEN_A);
	printf("\nand after inserting %d at the beginning it's ", newValue);
	print_array(B, LEN_A + 1); // Expect (505, 9, 505, 321, 117, 27, 64, 13, 9, 12, 208)

	printf("\nThe average of A[] is %f", average(A, LEN_A)); // Expect 128.5d
	printf("\nThere are %d items in A[] less than this.", less_than_average(A, LEN_A)); // expect 7

	printf("\n");
	reverse(A, LEN_A);
	print_array(A, LEN_A); // Expect (208, 12, 9, 13, 64, 27, 117, 321, 505, 9)

	printf("\n");
	rotate_right(A, LEN_A, 3);
	print_array(A, LEN_A); // Expect (321, 505, 9, 208, 12, 9, 13, 64, 27, 117)

	printf("\n");
	evens_on_left(A, LEN_A); // Expect (1358888978, 64, 12, 208, 117, 27, 13, 9, 9, 505)
	print_array(A, LEN_A);

	printf("\nThe index of the first occurrence of %d is %d.", 9, find(A, LEN_A, 9));
	printf("\nThe index of the last occurrence of %d is %d.", 9, find_last(A, LEN_A, 9));

	printf("\n");
	print_array(A, LEN_A);
	if (contains_dup(A, LEN_A))
		printf("\nA[] contains a dup");
	else
		printf("\nA[] doesn't contain a dup");

	printf("\n");
	print_array(B, sizeof(B)/sizeof(*B));
	if (contains_dup(B, LEN_A + 1))
		printf("\nB[] contains a dup");
	else
		printf("\nB[] doesn't contain a dup");

	printf("\n");
	print_array(A, sizeof(A)/sizeof(*A));
	printf("\nSecond largest is %i\n", secondLargest(A, LEN_A));
	return 0;
}

/* functions implementation */

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen). */
void print_array(int A[], int length) {
	printf("(");

	for (int i = 0; i < length; i++)
		printf((i < length - 1) ? "%i, " : "%i", A[i]);

	printf(")"); // We keep this ending parenthesis at the end just in case the array is empty
}

/* returns the average of the items in A[] or 0.0 if A is empty */
double average(int A[], int length) {
	double arraySum = 0;

	for (int i = 0; i < length; i++)
		arraySum += A[i];

	return arraySum / length;
}

/* returns the number of items in A that are less than the
   average of the items in A */
int less_than_average(int A[], int length) {
	double arrayAvg = average(A, length);
	int lowerThanAvg = 0;

	for (int i = 0; i < length; i++)
		if (A[i] < arrayAvg)
			lowerThanAvg++;

	return lowerThanAvg;
}

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length) {
	//int reversedArrContainer[length];

	for (int i = 0; i < length; i++) {
		int container = A[i];

		A[i] = A[length - i];
		A[length - i] = container;
	}

	/*for (int i = 0; i < length; i++)
		reversedArrContainer[length - 1 - i] = A[i];

	for (int i = 0; i < length; i++)
		A[i] = reversedArrContainer[i];*/
}

/* returns the second largest item in A[], or -1 if len < 2 */
int secondLargest(int A[], int length) {
	if (length < 2)
		return -1;

	int container[2] = { A[0], -2147483648 }; // First number in the array with the smallest possible int

	for (int i = 1; i < length; i++) {
		printf("\n%i > %i == %i\n", A[i], container[0], (A[i] > container[0]));
		if (A[i] > container[0]) {
			// Shift container numbers
			container[1] = container[0];
			container[0] = A[i];
		} else if (A[i] > container[1])
			container[1] = A[i];
	}

	/* for now return 0 as a placeholder.  We do this just so that the program
	   compiles without warning until we've finished */
	return container[1];
}

/* rotates the values in the array numPlaces to the right */
/* for example, if A[] is initially 10,20,30,40,50, and numPlaces=2 */
/* after the function finishes, A[] would be 40,50,10,20,30 */
void rotate_right(int A[], int length, int numPlaces) {
	if (length <= 1)
		return;

	if (numPlaces >= length) // Avoid weird stuff happening when numPlaces is greater than the length
		numPlaces = numPlaces % length;

	int rotatedContainer[numPlaces];
	int containerIndex = 0;

	// Store soon-to-be overwritten numbers
	for (int i = length - numPlaces; i < length; i++)
		rotatedContainer[containerIndex++] = A[i];

	// Shift numPlaces to the right
	for (int i = length - 1; i >= numPlaces; i--)
		A[i] = A[i - numPlaces];
	// Overwrite beginning numbers with rotated numbers
	for (int i = 0; i < numPlaces; i++)
		A[i] = rotatedContainer[i];
}

/* inserts the value n in A[] at the given index and shifts
   all other values up one position.  A[] contains length items.

   It is up to the caller to make sure that there is enough space
   in A[] to accomodate the new item, and that the index is valid. */
void insert(int A[], int n, int index, int length) {
	if (index >= length || index < 0) // Prevent index OOB
		return;

	if (length > 1) // Avoids an error in the for-loop if an array's length is == 1 where we would try doing A[1] = A[0]
		for (int i = length; i > index; i--)
			A[i] = A[i - 1];

	A[index] = n;
}

/* copies the first numItems from S to D. */
void array_copy(int D[], int S[], int numItems) {
	for (int i = 0; i < numItems; i++)
		D[i] = S[i];
}


/* sets the first len elements of A to initialValue */
void initialize(int A[], int len, int initialValue) {
	for (int i = 0; i < len; i++)
		A[i] = initialValue;
}

/* shuffles the values in A so that the even values
   are all to the left of the odd values */
void evens_on_left(int A[], int len) {
	int evenContainer[len], oddContainer[len];
	int evenIndex = 0, oddIndex = 0;

	for (int i = len; i > 0; i--)
		if (A[i] % 2 == 0) // Number is even
			evenContainer[evenIndex++] = A[i];
		else // Odd
			oddContainer[oddIndex++] = A[i];

	oddIndex = 0;

	for (int i = 0; i < len; i++)
		if (i < evenIndex) // Even insertion
			A[i] = evenContainer[i];
		else // Odd insertion
			A[i] = oddContainer[oddIndex++];
}

/* returns the index of the first occurrence of
 * x in A[] or -1 if x doesn't exist in A[] */
int find(int A[], int len, int x) {
	for (int i = 0; i < len; i++)
		if (A[i] == x)
			return i;

	return -1;
}

/* returns the index of the last occurrence of
 * x in A[] or -1 if x doesn't exist in A[] */
int find_last(int A[], int len, int x) {
	for (int i = len; i > 0; i--)
		if (A[i] == x)
			return i;

	return -1;
}

/* returns 1 if there is at least one element in A[]
   that is contained elsewhere in A[], or 0 if there isn't */
int contains_dup(int A[], int len) {
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (A[i] == A[j])
				return 1;

	return 0;
}