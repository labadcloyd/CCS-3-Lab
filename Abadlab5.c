#include <stdio.h>

// function prototype
void display(int []);

int main() {
  int n[10], i, tempnum, repeat = 0, menu, odd[2][5], even[2][5];

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {
		
		// making sure odd and even are initiated as zeros
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				odd[i][j] = 0;
				even[i][j] = 0;
			}
		}

		// asking for the input
		for (i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input positive integer: ");
			scanf("%d", &tempnum);
			n[i] = tempnum;
			while (tempnum < 1) {
				printf("Error: Integer must be a postive. \n");
				printf("Input positive integer: ");
				scanf("%d", &tempnum);
				n[i] = tempnum;
			}	
		}

		// saving the amount of numbers added to the array
		int oddCounter = 0, evenCounter = 0;

		/* SAVING THE EVEN OR ODD NUMBERS */
		for (int i = 0; i < 10; i++) {
			// saving even number in the first column
			if (evenCounter < 5) {
				if (n[i] % 2 == 0) {
					even[0][evenCounter] = n[i];
					evenCounter++;
				}
			} else if (evenCounter >= 5) {
				if (n[i] % 2 == 0) {
					even[1][evenCounter - 5] = n[i];
					evenCounter++;
				}
			}
			
			// saving odd number in the second column
			if (oddCounter < 5) {
				if (n[i] % 2 != 0) {
					odd[0][oddCounter] = n[i];
					oddCounter++;
				}
			} else if (oddCounter >= 5) {
				if (n[i] % 2 != 0) {
					odd[1][oddCounter - 5] = n[i];
					oddCounter++;
				}
			}
		}

		// displaying all integers from the array
		display(n);
		
		printf("\n");
		/* DISPLAYING THE 2D ARRAYS */
		// displaying the even array
		for (int i = 0; i < 2; i++) {
			if (i == 0) { printf("2-d even array"); }
			printf("\n");
			for (int j = 0; j < 5; j++) {
				printf("[%-1d][%-d] %-5d ", i, j,even[i][j]);
			}
		}
		printf("\n \n");
		// displaying the odd array
		for (int i = 0; i < 2; i++) {
			if (i == 0) { printf("2-d odd array"); }
			printf("\n");
			for (int j = 0; j < 5; j++) {
				printf("[%-1d][%-d] %-5d ", i, j,odd[i][j]);
			}
		}


		// asking if loop should be repeated
		printf("\n\nDo you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

  return 0;
};

void display(int n[10]) {
	int i;
	// printing all of the numbers
	printf("\n 1-d array \n");
	for (i = 0; i < 10; i++) {
		// making sure we make two rows
		if (i == 5) {
			printf("\n[%-1d] %-5d ", i, n[i]);
		} else {
			printf("[%-1d] %-5d ", i, n[i]);
		}
	}
	printf("\n");
}