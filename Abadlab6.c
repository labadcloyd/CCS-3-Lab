#include <stdio.h>

// function prototype
void display1d(int [], int);
void display2d(int [2][5], int);

int main() {
  int n[5], squared[5], tempnum, repeat = 0, origAndSquared[2][5];

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {

		// making sure origAndSquare is initiated as zeros
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				origAndSquared[i][j] = 0;
			}
		}

		// asking for the input
		for (int i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input integer between 5-50: ");
			scanf("%d", &tempnum);
			n[i] = tempnum;
			while (tempnum < 5 || tempnum > 50) {
				printf("Error: Integer must be between 5-50. \n");
				printf("Input integer between 5-50: ");
				scanf("%d", &tempnum);
				n[i] = tempnum;
			}	
		}

		// squaring all the values
		for (int i = 0; i < sizeof(n) / sizeof(int); i++) {
			squared[i] = (n[i] * n[i]);
		}
		// saving both values in a 2d array
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 0) { origAndSquared[i][j] = n[j]; }
				if (i == 1) { origAndSquared[i][j] = squared[j]; }
			}
		}

		display1d(n, 1);
		display1d(squared, 2);
		display2d(origAndSquared, 3);

		// asking if loop should be repeated
		printf("\n\nDo you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

  return 0;
};

void display1d(int n[5], int arrayNum) {
	// printing all of the numbers
	printf("\nArray Number %d \n", arrayNum);
	for (int i = 0; i < 5; i++) {
		printf("[%-1d] %-5d ", i, n[i]);
	}
	printf("\n");
}
void display2d(int n[2][5], int arrayNum) {
	// printing all of the numbers
	printf("\nArray Number %d \n", arrayNum);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			printf("[%-1d][%-1d] %-5d ", i, j, n[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}