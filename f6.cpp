/**
 *
 *
 * File			 : f6.Cpp
 * Programmer	 : Patel Bhumitkumar Kalpeshbhai
 * Assignment	 : Focused Assignment 6
 * First Version : 2023-02-24
 * student number: 8847159
 * Discription	 : This file contains code which add the double value to array 
 *					and provides the average and sum of first three input after that 
 *					gets seven floating input from user and gives the sum and average
 *					of seven number and fill all the seven number with 40
 *
 */

#include <iostream>
#pragma warning(disable:4996)

// below four lines are prototype for the functions
int getDouble(double* pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double* pAverage, double* pSum);
void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage);
void  fillArray(double values[], int numArray, double fillValue);




int main() {

	double d1, d2, d3, d4;

	printf("Enter four floating-point numbers, one per line:\n");
	if (!getDouble(&d1) || !getDouble(&d2) || !getDouble(&d3) || !getDouble(&d4)) {
		printf("Invalid input.\n");
		// if the entered value is not valid than return 1
		return 1;
	}

	double average = 0;
	double sum = 0;
	calculateStats(d1, d2, d3, d4, &average, &sum); // function call
	printf("The average and sum of the variables: %lf, %lf\n", average, sum);

	double values[7] = {};
	printf("Enter seven floating-point numbers, one per line:\n");
	for (int i = 0; i < 7; i++) {
		// if the input value is not valid than return 0
		if (!getDouble(&values[i])) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	calculateArrayStats(values, 7, &sum, &average); // function call of calculateArrayState
	printf("The average and sum of the array elements: %lf, %lf\n", average, sum);

	fillArray(values, 7, 40.0); // function call of fillArray which changes all value to 40
	printf("Array after filling with 40.0: ");
	// prints all the array after changing
	for (int i = 0; i < 7; i++) {
		printf("%lf", values[i]);
		if (i != 6) {
			printf(", ");
		}
	}
	printf("\n"); // creates the new line
	return 0;
}



/*
Function: getDouble()
Parameter: double *pNumber: pointer to a variable that is
filled in by the user input, if valid
Return Value: int: 1 if the user entered a valid floating-
point number, 0 otherwise
Description: This function gets a floating-point number
from the user. If the user enters a valid floating-point
number, the value is put into the variable pointed to by
the parameter and 1 is returned. If the user-entered value
is not valid, 0 is returned.
*/
int getDouble(double* pNumber) {
	char number[100] = {};  /* record stores the string */
	fgets(number, sizeof(number), stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(number, "%lf", pNumber) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}


/*
Function: calculateStats()
Parameters: double d1, d2, d3, d4: four floating-point
numbers
double *pAverage: pointer to a variable that
is filled in by this function with the average of d1, d2,
d3, and d4
double *pSum: pointer to a variable that is
filled in by this function with the sum of d1, d2, d3, and
d4
Return Value: none
Description: This function takes four floating-point
numbers passed as doubles and calculates the average and
sum of the numbers. Once calculated, the average gets put
into the variable pointed to by the pAverage parameter and
the sum gets put into the variable pointed to by the pSum
parameter.
*/
void calculateStats(double d1, double d2, double d3, double d4, double* pAverage, double* pSum) {
	*pSum = d1 + d2 + d3 + d4; // sum of all variables 
	*pAverage = *pSum / 4.0; // gets the average of all four variables
}


/*
Function: calculateArrayStats()
Parameters: double values[]: floating-point numbers
int numArray: number of array elements
double *pSum: pointer to a variable that is
filled in by this function with the sum of all elements in
the array
double *pAverage: pointer to a variable that
is filled in by this function with the average of all
elements in the array
Return Value: none
Description: This function takes an array of floating-point
(double) numbers, given the number of elements in the array
as a parameter, and calculates the average and sum of the
numbers. Once calculated, the average gets put into the
variable pointed to by the pAverage parameter and the sum
gets put into the variable pointed to by the pSum
parameter.
*/
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage) {
	*pSum = 0.0;
	for (int i = 0; i < numArray; i++) {
		*pSum += values[i]; // adds the sum value in values array at i position
	}
	*pAverage = *pSum / numArray;
}



/*
Function: fillArray()
Parameters: double values[]: floating-point numbers
int numArray: number of array elements
double fillValue: value to put into array
elements
Return Value: none
Description: This function takes an array of floating-point
(double) numbers, given the number of elements in the array
as a parameter, and puts the fillValue into each element of
the array.
*/
void  fillArray(double values[], int numArray, double fillValue){
	for (int i = 0; i < numArray; i++) {
		values[i] = fillValue; // fills the value of array with fillValue
	}
}