#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

//limits
#define MAX_TOKENS 100
#define MAX_STRING_LEN 100

// builtin commands
#define EXIT_STR "exit"
#define EXIT_CMD 0
#define UNKNOWN_CMD 99

char **tokens; // declare a pointer to the token_array
char *line; // declare a pointer to string_of_characters

size_t MAX_LINE_LEN = 10000;
FILE *fp; // file struct for stdin

void initialize(){
	assert((line = malloc(sizeof(char) * MAX_STRING_LEN)) != NULL); // allocate space for the whole line
	assert((tokens = malloc(sizeof(char *) * MAX_TOKENS)) != NULL); // allocate space for individual tokens
	assert((fp = fdopen(STDIN_FILENO, "r")) != NULL);// open stdin as a file pointer
}

void tokenize(char *theLine){ // akshay loves preeti, 97
	int token_count = 0;
	int size = MAX_TOKENS;
	char *this_token;

	printf("string ==> %s\n", theLine);
	printf("*string ==> %d\n", *theLine);
	printf("&string ==> %p\n", &theLine);

	; // divide the line into token

	printf("this_token ==> %s\n", this_token);

	while ((this_token = strsep(&theLine, " \t\v\f\n\r")) != NULL) {
		if (*this_token == '\0') continue; // null character

		tokens[token_count] = this_token;

		printf("Token %d: %s\n", token_count, tokens[token_count]);

		token_count++; // if there are more tokens than space ,reallocate more space

		if (token_count >= size)
		{
			size = size * 2;// 100 -> 200 number of tokens now
			assert((tokens = realloc(tokens, sizeof(char *) * size)) != NULL);
		}
	}
}

void read_command() {
	assert(getline(&line, &MAX_LINE_LEN, fp) > -1); // getline will reallocate if input exceeds max length
	printf("Shell read this line: %s\n", line);
	tokenize(line);// akshay loves preeti --> tokenize
}

int run_command() {
	if (strcmp(tokens[0], EXIT_STR) == 0) return EXIT_CMD;
	return UNKNOWN_CMD;
}

int main() {
	initialize(); // memory allocated and file loaded for reading

	do {
		printf("sh550> ");
		read_command();
	} while (run_command() != EXIT_CMD);

	return 0;
}
