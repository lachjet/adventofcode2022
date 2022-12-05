#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(char** argv, int argc) {
	char* filename = "input";
	char* buffer;
	buffer = malloc(sizeof(char)*10);
	size_t len = 10;
	size_t rlen;
	FILE *fptr = fopen(filename, "r");
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int curCallories = 0;
	int val = 0;
	int i = 0;

	while ((rlen = getline(&buffer, &len, fptr)) != -1) {
		val = atoi(buffer);
		if (val == 0) {
			printf("Total callories for elf %d is %d\n", i, curCallories);
			if (!(curCallories < max1) && (curCallories < max2)) {
				max1 = curCallories;
				printf("max1:%d\n", curCallories);
			} else if (!(curCallories < max2) && (curCallories < max3)) {
				max1 = max2;
				max2 = curCallories;
				printf("max2:%d\n", curCallories);
			} else if (!(curCallories <  max3)) {
				max1 = max2;
				max2 = max3;
				max3 = curCallories;
				printf("max3:%d\n", curCallories);
			}
			printf("max1: %d\nmax2: %d\nmax3: %d\n\n", max1, max2, max3);
			curCallories = 0;
			i++;
		} else {
			curCallories += val;
		}
		
	}
	val = max1 + max2 + max3;
	printf("Sum of max 3 callories is %d\n", val);

	fclose(fptr);
	free(buffer);
	return 0;
}
