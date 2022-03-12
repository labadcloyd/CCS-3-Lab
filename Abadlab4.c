#include <stdio.h>

// function prototype
int largest(int []), smallest(int []), sum(int []), product(int []);
float average(int []);
void display(int []);

int main() {
  int n[10], i, tempnum, repeat = 0, menu, twoDimensional[2][3];

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {
		for (i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input integer between 10-50: ");
			scanf("%d", &tempnum);
			n[i] = tempnum;
			while (tempnum < 10 || tempnum > 50) {
				printf("Error: Integer must be between 10-50, please try again. \n");
				printf("Input integer between 10-50: ");
				scanf("%d", &tempnum);
				n[i] = tempnum;
			}	
		}
		twoDimensional[0][0] = largest(n);
		twoDimensional[1][0] = smallest(n);
		twoDimensional[0][1] = sum(n);
		twoDimensional[1][1] = product(n);
		twoDimensional[0][2] = average(n);
		twoDimensional[1][2] = 0;

		// displaying all integers from the array
		display(n);
		// displaying all integers from the two dimensional array
		for (int j = 0; j < 2; j++) {
			printf("\v");
			for (int k = 0; k < 3; k++) {
				if (j == 0 && k == 2) {
					printf("\t | %-12f |", average(n));
				} else {
					printf("\t | %-12d |", twoDimensional[j][k]);
				}
			}
		}

		
		// asking if loop should be repeated
		printf("\n\nDo you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

  return 0;
};

int largest(int num[10]) {
	int final, i;
	// looping through the array checking each if they are the smallest
	for (i = 0; i < 10; i++) {
		if (num[i] > final) {
			final = num[i];
		};
	}
	return final;
}

int smallest(int num[10]) {
	int final, i;
	// looping through the array checking each if they are the smallest
	for (i = 0; i < 10; i++) {
		if (num[i] < final) {
			final = num[i];
		};
	}
	return final;
}

float average(int num[10]) {
	int i;
	float final;
	// looping through the array adding each to the final float
	for (i = 0; i < 10; i++) {
		final += num[i];
	}
	final = (final/10);
	return final;
}

int sum(int num[10]) {
	int i, final = 0;
	// looping through the array adding each to the final int
	for (i = 0; i < 10; i++) {
		final = final + num[i];
	}
	return final;
}

int product(int num[10]) {
	int i, final;
	// looping through the array adding each to the final int
	for (i = 0; i < 10; i++) {
		if (i == 0) {
			final = num[i];
		}
		if (i > 0) {
			final *= num[i];
		}
	}
	return final;
}


void display(int n[10]) {
	int i;
	// printing all of the numbers
	printf("\n \n integers in the array: ");
	for (i = 0; i < 10; i++) {
		printf(" %d,", n[i]);
	}
}