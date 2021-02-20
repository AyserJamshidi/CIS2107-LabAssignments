//
// Created by Ayser Jamshidi on 2/11/21.
//

#include <printf.h>

void copy_A(int A[], int B[], int len);

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {-1, -2, -3, -4, -5};

	copy_A(a, b, 4);

	for (int i = 0; i < 5; i++)
		printf("%i, ", b[i]);
}

void copy_A(int A[], int B[], int len) {
	for (int i = 0; i < len; i++)
		B[i] = A[i];
}