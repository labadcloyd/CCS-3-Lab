#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	typedef struct Student {
		int 	Id_number;
		char 	Name[25];
		float MT_Exam;
		float	Final_Exam;
		float	Final_Grade;
		char	Letter_Grade[10];
		float	Numeric_Grade;
	} student;
	

	int numOfRec = 0;
	struct Student StudentRecords[10] = {};

		// asking for the number of records
		printf("Input number of records(0-10): ");
		scanf("%d", &numOfRec);
		//error handling
		while (numOfRec < 1 || numOfRec > 10) {
			printf("Error: you can only input a maximum of 10 records \n");
			printf("Input number of records(maximum of 10): ");
			scanf("%d", &numOfRec);
		}

		// asking for the records
		int i = 0;
		while (i < numOfRec) {
			printf("\n");
			StudentRecords[i].Id_number = 1001 + i;
			printf("Enter name of student: ");
			scanf(" %s", StudentRecords[i].Name);

			printf("Enter MT exam grade (0-100): ");
			scanf("%f", &StudentRecords[i].MT_Exam);
			// error handling
			while (StudentRecords[i].MT_Exam < 0 || StudentRecords[i].MT_Exam > 100) {
				printf("Error: grade must be between 0-100: ");
				printf("\nEnter MT exam grade: ");
				scanf("%f", &StudentRecords[i].MT_Exam);
			}
			

			printf("Enter Final exam grade (0-100): ");
			scanf("%f", &StudentRecords[i].Final_Exam);
			// error handling
			while (StudentRecords[i].Final_Exam < 0 || StudentRecords[i].Final_Exam > 100) {
				printf("Error: grade must be between 0-100: ");
				printf("\nEnter Final exam grade: ");
				scanf("%f", &StudentRecords[i].Final_Exam);
			}

			StudentRecords[i].Final_Grade = ((StudentRecords[i].MT_Exam * 0.4) + (StudentRecords[i].Final_Exam * 0.6));
			StudentRecords[i].Numeric_Grade = ((2 * StudentRecords[i].Final_Grade - 60) / 35);
			
			if (StudentRecords[i].Final_Grade < 55) {
				strcpy(StudentRecords[i].Letter_Grade, "F  ");
			} else if (StudentRecords[i].Final_Grade > 54 && StudentRecords[i].Final_Grade < 65) {
				strcpy(StudentRecords[i].Letter_Grade, "D  ");
			} else if (StudentRecords[i].Final_Grade > 64 && StudentRecords[i].Final_Grade < 80) {
				strcpy(StudentRecords[i].Letter_Grade, "C  ");
			} else if (StudentRecords[i].Final_Grade > 79 && StudentRecords[i].Final_Grade < 95) {
				strcpy(StudentRecords[i].Letter_Grade, "B  ");
			} else if (StudentRecords[i].Final_Grade > 94 && StudentRecords[i].Final_Grade < 101) {
				strcpy(StudentRecords[i].Letter_Grade, "A  ");
			}

			i++;
		}

	// printing the results
	i = 0;
	printf("\n%*s", 12, "ID Number");
	printf("%*s", 	22, "Name");
	printf("%*s", 	16, "MT Exam");
	printf("%*s", 	16, "Final Exam");
	printf("%*s", 	16, "Final Grade");
	printf("%*s", 	16, "Letter Grade");
	printf("%*s", 	16, "Numeric Grade");
	while (i < numOfRec) {
		printf("\n%*d", 12, StudentRecords[i].Id_number);
		printf("%*s", 	22, StudentRecords[i].Name);
		printf("%*.0f", 16, StudentRecords[i].MT_Exam);
		printf("%*.0f", 16, StudentRecords[i].Final_Exam);
		printf("%*.0f", 16, StudentRecords[i].Final_Grade);
		printf("%*c", 	16, StudentRecords[i].Letter_Grade[0]);
		printf("%*.1f", 16, StudentRecords[i].Numeric_Grade);
		i++;
	}
	

  return 0;
};