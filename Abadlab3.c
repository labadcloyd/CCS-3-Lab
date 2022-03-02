#include <stdio.h>

// function prototype
int largest(int []);
int smallest(int []);
float average(int []);
int sum(int []);
int product(int []);
void display(int []);

int main() {
  int n[10], i, tempnum, repeat = 0, menu;

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {
		for (i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input integer: ");
			scanf("%d", &tempnum);
			n[i] = tempnum;
		}

		printf("\nChoose what to output: \n");
		printf("1. Largest Integer\n");
		printf("2. Smallest Integer\n");
		printf("3. Average of all Integers\n");
		printf("4. Sum of all Integers\n");
		printf("5. Product of all Integers\n");
		printf("Enter the number of your choice (ex. 2): ");
		scanf("%d", &menu);
		// theres a bug that requries me to seperate this line separator
		printf("\n");

		// conditionally printing what the user wants
		if (menu == 1) {
			printf("Largest integer in the array: %d \n", largest(n));
		} else if (menu ==  2) {
			printf("Smallest integer in the array: %d \n", smallest(n));
		} else if (menu == 3) {
			printf("Average integer in the array: %f \n", average(n));
		} else if (menu == 4) {
			printf("Sum of all integers in the array: %d \n", sum(n));
		} else if (menu == 5) {
			printf("Product of all integers in the array: %d \n", product(n));
		} else {
			printf("Invalid input");
		}

		// displaying all integers from the array
		display(n);
		
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
	printf("integers in the array: ");
	for (i = 0; i < 10; i++) {
		printf(" %d,", n[i]);
	}
}