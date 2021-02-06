#include <stdio.h>

void GetFile() {

}

int main(int argc, char **argv) {
	FILE *fp;
	fp = fopen("TestFile.txt", "r");

	if (fp == NULL) {
		printf("File was not found!");
		return 1;
	}

	/*
	 *
	 */
	int curChar = fgetc(fp);

	/*
	 *
	 */
	int previousChar = -1;

	/*	boolean insideString:
	 *		True 	= Can NOT search for multi-line comment characters
	 *		False	= Can search for multi-line comment characters
	 *
	 *		This is useful for detecting when we're in a string
	 */
	int insideString = 0;

	/*
	 *
	 */
	int insideComment = 0;

	while (!feof(fp)) { // While we haven't reached EOF
		if (insideComment) { // Ignore everything until */ is found!
			if (curChar == '/' && previousChar == '*') {
				insideComment = 0;
			}
		} else {
			if (curChar == '"' && (previousChar != '\\' && previousChar != '\'')) {
				insideString = 1;
			}

			if (!insideString && curChar == '*' && previousChar == '/') {
				insideComment = 1;
			}
		}

		if (!insideComment)
			printf("%c", curChar);

		previousChar = curChar;
		curChar = fgetc(fp);
	}

	fclose(fp);

	return 0;
}