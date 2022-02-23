#include <stdio.h>

/*---function prototype---*/
long toBinary(int);

int main() {
  int n, bin;

	/* ---fething decimal number--- */
  printf("Input a decimal number: ");
  scanf("%d", &n);

	/* ---converting decimal then printing--- */
  bin = toBinary(n);
  printf("%d in decimal is =  %ld in binary.", n, bin);

  return 0;
}

long toBinary(int n) {
 	long bin = 0;
  int rem, i = 1;

  while (n!=0) {
		/* ---remainder--- */
    rem = n % 2;
		// printf(" n(%d) modulo 2 is: %d \n", n, rem);

		/* ---dividing n to 2 to use the quotient in the next iteration---*/
    n = n/2;
	
		/*
			! here comes the hard part 
			adding the results without using strings since the binary
			is basically a concatenation of all the remainder of n in
			each iteration of this loop in a reversed order.
		*/
		/*
			here we add the binary to the product of rem and i
			take note each iteration increases the number of digits of i
			so at the 4th iteration i would be 1000
		*/
    bin += rem * i;
		// printf("current binary is: %d \n", bin);

		/* ---Increasing the number of digits by 1 each in each iteration--- */
    i *= 10;
		// printf("i is: %d \n", i);
  }

  return bin;
}
