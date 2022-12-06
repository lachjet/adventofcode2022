#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROCK 1
#define PAPER 2
#define SCISORS 3

#define WIN 6
#define DRAW 3
#define LOSS 0

int main(char** argv, int argc) {
	char* filename = "input";
	char* buffer = malloc(sizeof(char) * 5);
	char* token;
	size_t len;
	FILE *fptr = fopen(filename, "r");
	int score = 0;
	int i = 1;
	int winstate;
	int you;
	int op;

	while ((len = getline(&buffer, &len, fptr)) != -1) {
		printf("Round %d\n", i);
		printf("%s", buffer);
		token = strtok(buffer, " ");
		if (token[0] == 'A') {
			printf("Opponent Chooses Rock\n");
			op = ROCK;
		} else if (token[0] == 'B') {
			printf("Opponent Chooses Paper\n");
			op = PAPER;
		} else if (token[0] == 'C') {
			printf("Opponent Chooses Scisors\n");
			op = SCISORS;
		}

		token = token + 2;
		if (token[0] == 'X') {
			printf("You Must Loose\n");
			you = (op - 1) % 3;
			if (you == 0)
				you = 3;
		} else if (token[0] == 'Y') {
			printf("You Must Draw\n");
			you = op;
			score += 3;
		} else if (token[0] == 'Z') {
			printf("You Must Win\n");
			you = (op % 3) + 1;
			score += 6;
		}
		if (you == SCISORS) {
			printf("You choose scisors\n");
			score += 3;
		} else if (you == PAPER) {
			printf("You choose Paper\n");
			score += 2;
		} else {
			printf("You Choose Rock\n");
			score += 1;
		}
		i++;
		printf("\n");
	}
	printf("Final score is %d\n", score);

	fclose(fptr);
	free(buffer);
	return 0;
}
