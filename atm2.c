#include <stdio.h>
#include <stdlib.h>

int main () {
  
    char choice[10];
    int numbers;
	float amount=0.00, balance;
	printf("[1] Initialize\n\n");
	printf("[2] Deposit \n\n");
	printf("[3] Withdraw \n\n");
	printf("[4] Display \n\n");
	printf("[5] Exit \n\n");
	printf("[Developed by: Your Name]");
	
do
{
	printf("\nSelect your transaction:\n");
	scanf("%s", &choice);
	numbers = atoi(choice);

	do
	{
		if(numbers==1){
				balance = 0.0;
				printf("Input an amount: \n");
				scanf("%f", &amount);
				balance+=amount;
				printf("\nYour balance is Php %.2f\n", balance);
				break;
			}
			else if(numbers==2){
				printf("Enter amount to deposit: \n");
				scanf("%f", &amount);
				balance+=amount; 
				printf("\nYour new balance is Php %.2f", balance);
				break;
			}
			else if(numbers==3){
				printf("Enter amount to withdraw: \n");
				scanf("%f", &amount);
				
				 	if (balance < amount)
					 {
						printf("Sorry, you do not have enough balance. Please try again. . . \n");
						break;
					 }
					 else
					 {
					 	balance-=amount;
						 printf("\nYour remaining balance is Php %.2f \n", balance);
						 break;
					 }
			}
			else if(numbers==4){
				printf("Your available balance is %.2f\n",balance);
				break;
			}
			else if(numbers==5){
				printf("Thank you for using our program\n");
				return(0);
				break;
			}
			else {
				printf("Error! Please Enter Correct Selection\n");
				break;
			}
	}while(numbers==1||numbers==2||numbers==3||numbers==4||numbers==5);

}while(numbers!=1||numbers!=2||numbers!=3||numbers!=4||numbers!=5);

}
