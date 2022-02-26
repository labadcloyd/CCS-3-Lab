#include <stdio.h>

// function prototype
int largest(int num[5]);

int main() {
  int n[5], i, tempnum, repeat = 0;

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {
		for (i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input integer: ");
			scanf("%d", &tempnum);
			// theres a bug that requries me to seperate this line separator
			printf("\n");
			n[i] = tempnum;
		}
		printf("integers in the array: %d, %d, %d, %d, %d \n", n[0], n[1], n[2], n[3], n[4]);
		printf("largest integer is: %d \n \n", largest(n));
		
		// asking if loop should be repeated
		printf("Do you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

  return 0;
};

int largest(int num[5]) {
	int final, i;

	// looping through the array checking each if they are the largest
	for (i = 0; i < 5; i++) {
		if (num[i] > final) {
			final = num[i];
		};
	}

	return final;
}