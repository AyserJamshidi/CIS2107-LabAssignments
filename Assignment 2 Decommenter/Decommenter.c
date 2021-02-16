#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 255

#define LINE 0
#define COLUMN 1

#define CURRENT 0
#define PREVIOUS 1

// Header
int loadFile();
void errorCheck();
int endOfBlockComment();
int currentCharTogglesString();

FILE *readFile, *writeFile; // File pointer
char givenFileName[BUFFER_SIZE];

// Var initialization
int text[] = {-1, -1};
int position[] = {1, 1}; // { line number, column number } of text cursor position

int lastComment[] = {0, 0}; // { line number, column number } of the beginning of the last comment block

// Booleans
int inString = 0; // If we found a string or char* to prevent eating block comments
int inCommentLine = 0; // If we found // in proper conditions
int inCommentBlock = 0; // If we found /* in proper conditions
int canIgnoreNext = 0; // Used to ignore the next character after we enter a comment block

int main() {
	if (loadFile() != 0) { // If we had errors while loading a file
		printf("\nFile could not be found.");
		return 1;
	}

	remove("decommented.e");
	writeFile = fopen("decommented.e", "w");

	// We set prevChar to curChar then discard the result with the sequencing point.  We then loop if the new char is not EOF.
	while ((text[PREVIOUS] = text[CURRENT]), (text[CURRENT] = fgetc(readFile)) != EOF) {
		// If we hit a new line then add a line, reset the column and set that we are no longer in an in-line comment
		if (text[CURRENT] == '\n') {
			position[LINE]++;
			position[COLUMN] = 1;
			inCommentLine = 0;
		} else
			position[COLUMN]++;

		// If inside /*, check if we can ignore the next
		if (inCommentBlock) { // Inside / *
			if (endOfBlockComment()) // If we found * /, time to start outputting again.
				inCommentBlock = 0;
			else
				canIgnoreNext = 0;
		} else if (!inCommentLine) { // Comment line or block not reached yet.
			if (currentCharTogglesString()) // If we're entering/exiting a string or char*, ignoring '"' and \"
				inString = !inString; // Toggle

			if (!inString && text[CURRENT] == '/') { // Current char is / and we're not in a string
				// Store current character as previous so we don't lose it and then store the next letter as our current so we can check if we found /*
				text[PREVIOUS] = text[CURRENT];
				text[CURRENT] = fgetc(readFile);
				position[COLUMN]++;

				if (text[CURRENT] == '/') { // Found //
					inCommentLine = 1; // Start a comment line since we have a double slash.
				} else if (text[CURRENT] == '*') { // Found /*
					// Start comment block and set the last comment block position to keep track if an error occurs.
					inCommentBlock = 1;
					canIgnoreNext = 1;
					lastComment[LINE] = position[LINE];
					lastComment[COLUMN] = position[COLUMN] - 2; // Subtract 2 because we want to move back 2 characters (char / and char *)
				} else { // We found a stray /, probably in a string or something. Output both chars.
					printf("%c", text[PREVIOUS]);
					fputc(text[PREVIOUS], writeFile);
				}
			}

			if (!inCommentLine && !inCommentBlock) {
				printf("%c", text[CURRENT]);
				fputc(text[CURRENT], writeFile);
			}
		} // If we skipped everything then we're in a comment line
	}

	errorCheck();
	fclose(readFile);
	fclose(writeFile);
	return 0;
}

int loadFile() {
	printf("File name: ");
//	fgets(givenFileName, BUFFER_SIZE, stdin);
//	puts(givenFileName);
	gets(givenFileName);
	printf("\nAttempting to read file %s\n", givenFileName);

	readFile = fopen(givenFileName, "r");

	return readFile == NULL;
}

void errorCheck() {
	if (inCommentBlock) // If we're done reading the file and are still in a comment block
		printf("\nerror: unterminated comment at %i:%i\n", lastComment[LINE], lastComment[COLUMN]);
}

int endOfBlockComment() {
	return canIgnoreNext == 0 && (text[PREVIOUS] == '*' && text[CURRENT] == '/');
}

int currentCharTogglesString() {
	return text[CURRENT] == '"' && text[PREVIOUS] != '\\' && text[PREVIOUS] != '\'';
}