#include <stdio.h>

// function prototype
void swap(char*, char*, char*, char*);

int main() {
  int repeat = 0;
	char characters[4] = {"a"};

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {

		// asking for the input
		printf("Input four characters: ");
		for (int i = 0; i < 4; i++) {
			scanf(" %c", &characters[i]);
		}

		// printing the output 4 times
		printf("\nOutput after each swap:\n");

		for (int i = 0; i < 4; i++) {
			swap(&characters[0], &characters[1], &characters[2], &characters[3]);
		}

		// asking if loop should be repeated
		printf("\n\nDo you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

	
  return 0;
};

void swap( char* first, char* second, char* third, char* fourth) {
	// making copies of each var
	char firstCopy, secondCopy, thirdCopy, fourthCopy;
	firstCopy = *first;
	secondCopy = *second;
	thirdCopy = *third;
	fourthCopy = *fourth;

	// switching the places using the copies
	*first = secondCopy;
	*second = thirdCopy;
	*third = fourthCopy;
	*fourth = firstCopy;

	printf("%c %c %c %c \n", *first, *second, *third, *fourth);
};