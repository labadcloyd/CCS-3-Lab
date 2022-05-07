#include <stdio.h>


int main() {
	float arr[2][2][3];
	int i, j, k;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				arr[i][j][k] = i + (j+k)*4;
				printf("arr[%d][%d][%d] = %.2f\n", i, j, k, arr[i][j][k]);
			}
		}
	}
}
