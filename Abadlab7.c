#include <stdio.h>

// function prototype
void display1d(int [], int);
void display3d(int [2][2][3], int);

int main() {
  int n[12], tempnum, repeat = 0, greaterThan30[2][2][3], lessThan30[2][2][3];

	// making sure the cli program runs until the user enters 0 when asked to continue
	while (repeat == 0) {

		// making sure origAndSquare is initiated as zeros
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k++) {
					greaterThan30[i][j][k] = 0;
					lessThan30[i][j][k] = 0;
				}
			}
		}

		// asking for the input
		for (int i = 0; i < sizeof(n) / sizeof(int); i++) {
			printf("Input positive integer: ");
			scanf("%d", &tempnum);
			n[i] = tempnum;
			while (tempnum < 1) {
				printf("Error: Integer must be positive. \n");
				printf("Input positive integer: ");
				scanf("%d", &tempnum);
				n[i] = tempnum;
			}	
		}

		// saving the values
		int gtCounter = 0, ltCounter = 0;
		for (int i = 0; i < sizeof(n) / sizeof(int); i++) {
			if (n[i] < 30) {
				if (ltCounter <= 3) {
					lessThan30[0][0][ltCounter] = n[i];
					ltCounter++;
				} else if (ltCounter >= 4 && ltCounter <= 6) {
					lessThan30[0][1][ltCounter -3] = n[i];
					ltCounter++;
				} else if (ltCounter >= 7 && ltCounter <= 9) {
					lessThan30[1][0][ltCounter -6] = n[i];
					ltCounter++;
				} else if (ltCounter >= 10 && ltCounter <= 12) {
					lessThan30[1][1][ltCounter -9] = n[i];
					ltCounter++;
				}
			}
			else if (n[i] >= 30) {
				if (gtCounter <= 3) {
					greaterThan30[0][0][gtCounter] = n[i];
					gtCounter++;
				} else if (gtCounter >= 4 && gtCounter <= 6) {
					greaterThan30[0][1][gtCounter -3] = n[i];
					gtCounter++;
				} else if (gtCounter >= 7 && gtCounter <= 9) {
					greaterThan30[1][0][gtCounter -6] = n[i];
					gtCounter++;
				} else if (gtCounter >= 10 && gtCounter <= 12) {
					greaterThan30[1][1][gtCounter -9] = n[i];
					gtCounter++;
				}
			} 
		}

		display1d(n, 1);
		display3d(lessThan30, 2);
		display3d(greaterThan30, 3);

		// asking if loop should be repeated
		printf("\n\nDo you want to try again? (0 for yes, 1 for no): ");
		scanf("%d", &repeat);
	}

  return 0;
};

void display1d(int n[5], int arrayNum) {
	// printing all of the numbers
	printf("\nArray Number %d \n", arrayNum);
	for (int i = 0; i < 12; i++) {
		printf("[%-1d] %-5d ", i, n[i]);
	}
	printf("\n");
}
void display3d(int n[2][2][3], int arrayNum) {
	// printing all of the numbers Cloyd Abad CCS 3 D
	if (arrayNum == 2) { printf("\nNumbers Less than 30\n"); }
	if (arrayNum == 3) { printf("\nNumbers Greater than 30\n"); }
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				printf("[%-1d][%-1d][%-1d] %-5d ", i, j, k, n[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}