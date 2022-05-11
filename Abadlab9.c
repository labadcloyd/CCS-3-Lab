#include <stdio.h>
#include <string.h>

int main() {
  int strRepeatCount = 0;
	char strings[25] = {}, singleChar[1] = {};
	

		// asking for the line input
		printf("Input a line: ");
		gets(strings);

		while (strlen(strings) > 25 || strlen(strings) < 1) {
			printf("\nError: line must not exceed 25 characters or must not be below 1");
			printf("\nInput a line: ");
			gets(strings);
		}
		

		printf("Input a character: ");
		scanf("%c", &singleChar);

		for (int i = 0; i < strlen(strings); i++) {
			if (strings[i] == singleChar[0]) {
				strRepeatCount++;
			}
		}
		printf("The letter %c appears in %s %d time(s).", singleChar[0], strings, strRepeatCount);

	
  return 0;
};