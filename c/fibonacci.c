#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) { // function declaration with an int argument which signifies the limit to which we have to print the series

	int f0=0, f1=1, i, fi; // variable declarations
	printf("%s ", "0 1"); // printing first sequence of the series
	for (i = 2; i <= n; i++) { // starting from 2 because we have already consisdered 0 and 1 to begin the series and iterating till nth
		fi = f0 + f1; // add the last two and store in the sum fi.
		printf("%d ", fi); // printing the sum ie. the current number in the series.
		f0 = f1; // replacing the f0 value with the value of f1
		f1 = fi; // replacing the f1 value with the value of sum ie. fi
	}

	return f1; // returning the nth number
}

int main() { // init program
	int nthNumber = fibonacci(20); // storing the nth number into variable nthNumber
	printf("\nNth number is %d\n", nthNumber); // using stdio's printf function to outpout the nthNumber on the stream
	return 0; // ending the program exxecution
}
