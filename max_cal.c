/*
** Author: Muhammad Abdullah Khan
** Version: 1.0
** Topic: Matrix Calculator
** Rights: Open Source. Please make use in your own programms. Please learn and understand in case using for 
** Assignments and tasks etc.
*/


#include <stdio.h>



// Max matrix size
#define MAX_COL 50

//Function declerations

// this function takes input matrices from the file
void parse_file(int a[MAX_COL][MAX_COL][MAX_COL]);
// This function checks the sizes of the matrices
// send the matrix and the variables as pointers to get the rows and cols
void get_Max_Size(int max[MAX_COL][MAX_COL] , int *row , int *col);
// This function is used to pick matrices from the file...
// Send the master Matrix and send any two you want to populate and the matrix number in sequence you wish
// to populate into the matrices.
void parse_array(int main_array[MAX_COL][MAX_COL][MAX_COL], int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int num_a, int num_b);
// Simple subtraction
void subtract(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
// Simple addition
void addition(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
// Simple unit tests for some functions
void unit_test_add(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void unit_test_sub(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void unit_test_multiply(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);

//Simple element by element multiplication
void simple_mul(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
// Strasson multiplication function
void multiply_strasson(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);

// Helper functions
// Simple printing function
void print_array(int temp_res[MAX_COL][MAX_COL]);
//Clearing Matrix and populating it with zeros
int clear_max(int max_to_be_cleared[MAX_COL][MAX_COL]);
// This function makes a matrix a perfect square... To be used in strasson multiplication
// This function populates the missing places with zeroes
void size_maker(int max[MAX_COL][MAX_COL], int row, int col);

/*
* max_cal.c
*
*  Created on: Feb 19, 2015
*      Author: Abdullah Khan
*/


int main_array[50][50][50];
int a[50][50];
int b[50][50];
int c[50][50];

int main() {
	parse_file(main_array);
	parse_array(main_array, a, b, 0, 1);
	print_array(a);
	print_array(b);

	addition(a, b, c);

	printf("Here Is the result of addition of a and b\n");
	print_array(c);

	printf("Here Is the result of addition of a and b\n");
	subtract(a , b , c);
	print_array(c);


	//Multiplication
	

	printf("Second mul function used here!!");
	simple_mul(a, b, c);
	print_array(c);


	//checking size maker
	size_maker(a, 2, 2);
	print_array(a);
	getchar();
	return 1;
}

// This function gets the no of rows and cols for some Matrix
void get_Max_Size(int max[MAX_COL][MAX_COL] , int *row , int *col){

	int i = 0;
	int j = 0;
	// Simply goto the end of the array col wise and add cols
	while (max[i][j] != NULL) {
		*col++;
		j++;
	}
	j = 0;
	// Simply goto the end of the array row wise and add rows
	while (max[i][j] != NULL) {
		*row++;
		i++;
	}

}


// THis function will be used to perform strasson multiplication this will square the matrices perfectly
void size_maker(int max[MAX_COL][MAX_COL] , int row , int col) {
	int local_row = row;
	int local_col = col;
	
	if ((row+1) % 2 == 0 && (col+1) % 2 == 0) {
		printf("I am here");
		return;
	}
	else {
		if ((row+1) % 2 != 0) {
			while (col != -1) {
				max[row+1][col] = 0;
				col--;
				printf("I am inside col maker");
			}
		}
		row = local_row;
		col = local_col;
		if((col+1) % 2 != 0){
			while (row+1 != -1) {
				printf("I am inside row maker");
				max[row+1][col+1] = 0;
				row--;
			}
		}
		return;
	}
}



/*
Here is the size checker
This will check the array size and compare the two arrays
If the arrays are fit for addition it will add else return 1;
Similarly the same function will be used for testing if the arrays are fit for subtraction
and multiplication!*/



void parse_file(int a[MAX_COL][MAX_COL][MAX_COL]) {
	char c[1000];
	char number[5];
	FILE* f;
	// Pick the data into the buffer from file
	// Error detection minute applied!
	if ((f = fopen("f.txt", "r")) == NULL) {
		printf("File cannot be opened!");
	}
	fgets(c, 1000, f);
	printf("String read: %s\n", c);
	fclose(f);
	// close the file
	int i = 0;
	int j = 0;
	// will be used in
	int qux = 0;
	int bar = 0;
	int foo = 0;
	while (c[i] != NULL) { 	// Keep parsing until the string is not null!
		if (c[i] == '[') { 	// When the character in the string is the start of array go into if
			while (c[i] != ']') { 			//Keep taking elements until the array doesnot end
				if (c[i] > 47 && c[i] < 58) { 			//In case of number put in array!
					number[j] = c[i];
					j++;
				}
				else if (c[i] == ',') { 				// When the number ends with comma
					a[foo][bar][qux] = atoi(number);	//Put the number into the array
					qux++;					// Increment the array position
					j = 0;						// Then start taking the next number
				}
				else if (c[i] == ';') { 				// IN case of collon means row ends
					a[foo][bar][qux] = atoi(number); 	// Insert the last number into the array
					qux = 0; 					// Set the Collum position for array
					j = 0; 					//Start taking number
					bar++;					// Increment the row position of array!
				}
				else { 						// IN case of some other character print error
					printf("Invalid Character! %c",c[i]);
				}
				i++; 							// Increment while
			}
			a[foo][bar][qux] = atoi(number); 			//In case array ends take the last number
			qux = 0; 							// Set the col no
			bar = 0;							// Set the row no
			j = 0;								// Set the parser array
			foo++;							// Increment the array number
		}
		i++;									// Increment the while
	}
	return;
}


// THis function takes the main array and can parse any array required by the user in the a and b arrays
void parse_array(int main_array[MAX_COL][MAX_COL][MAX_COL], int array_A[MAX_COL][MAX_COL], int array_B[MAX_COL][MAX_COL], int array_num_A, int array_num_B) {
	int j = 0;
	int i = 0;
	while (main_array[array_num_A][i][j] != NULL) {
		while (main_array[array_num_A][i][j] != NULL) {
			array_A[i][j] = main_array[array_num_A][i][j];
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (main_array[array_num_B][i][j] != NULL) {
		while (main_array[array_num_B][i][j] != NULL) {
			array_B[i][j] = main_array[array_num_B][i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return;
}



// Simple subtraction
void subtract(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]) {
	int j = 0;
	int i = 0;
	int a_rows = 0;
	int a_cols = 0;
	int b_rows = 0;
	int b_cols = 0;

	get_Max_Size(a, &a_rows, &a_cols);
	get_Max_Size(a, &b_rows, &b_cols);
	if (a_rows == b_rows && a_cols == b_rows) {
		while (a[i][j] != NULL) {
			while (a[i][j] != NULL) {
				c[i][j] = a[i][j] - b[i][j];
				j++;
			}
			i++;
			j = 0;
		}
	}
	else {
		printf("These arrays cannot be subtracted because of wrong format!");
	}
}




// Simple Addition
void addition(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]) {
	
	int a_rows = 0;
	int a_cols = 0;
	int b_rows = 0;
	int b_cols = 0;

	get_Max_Size(a, &a_rows, &a_cols);
	get_Max_Size(a, &b_rows, &b_cols);
	if (a_rows == b_rows && a_cols == b_rows) {
		int j = 0;
		int i = 0;
		while (a[i][j] != NULL) {
			while (a[i][j] != NULL) {
				c[i][j] = a[i][j] + b[i][j];
				j++;
			}
			i++;
			j = 0;
		}
	}
	else {
		printf("These arrays cannot be added because of wrong format");
	}
	return;
}


// Simple Addition Unit Test
void unit_test_add(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the addition test");
	// Parse arrays from file
	parse_array(main_array, temp_a, temp_b, 0, 1);
	// Add the arrays
	addition(a, b, c);
	
	print_array(c);
	return;
}

// SImple subtraction Unit Test
void unit_test_sub(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the subtraction test");
	parse_array(main_array, temp_a, temp_b, 0, 1);
	subtract(temp_a, temp_b, temp_res);
	print_array(temp_res);
	return;
}

// Simple multiplication Unit Test
void unit_test_multiply(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the Multiplication test");
	parse_array(main_array, temp_a, temp_b, 0, 1);
	simple_mul(temp_a, temp_b], temp_res)
	print_array(temp_res);
	return;
}


// Matrix Printing Function
// GOes element by element and prints the elements of the array
void print_array(int temp_res[MAX_COL][MAX_COL]) {
	int j = 0;
	int i = 0;
	
	while (temp_res[i][j] != NULL) {
		printf("\n| ");
		while (temp_res[i][j] != NULL) {
			
			printf("%d ", temp_res[i][j]);
			j++;
		}
		printf("|");
		i++;
		j = 0;
	}
	printf("\n");
	
	
	return;
}


void multiply_strasson(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]) {
	
	int a_rows = 0;
	int a_cols = 0;
	int b_rows = 0;
	int b_cols = 0;
	
	get_Max_Size(a, &a_rows, &a_cols);
	get_Max_Size(b, &b_rows, &b_cols);

	//Check if the matrix are fit for multiplication!!
	if (a_cols == b_rows) {
		size_maker(a, a_rows, a_cols);
		size_maker(b, b_rows, b_cols);
	}
	int d[7] = { 0 };
	d[0] = (a[1][1] + a[2][2]) * (b[1][1] + b[2][2]);
	d[1] = (a[2][1] + a[2][2]) * (b[1][1]);
	d[3] = a[1][1] * (b[1][2] - b[2][2]);
	d[4] = a[2][2] * (b[2][1] - b[1][1]);
	d[5] = (a[1][1] + a[1][2]) * b[2][2];
	d[6] = (a[2][1] - a[1][1]) * (b[2][1] + b[2][2]);
	d[7] = (a[1][2] - a[2][2]) * (b[2][1] + b[2][2]);

	c[1][1] = d[1] + d[4] - d[5] + d[7];
	c[1][2] = d[3] + d[5];
	c[2][1] = d[2] + d[4];
	c[2][2] = d[1] - d[2] + d[3] + d[6];
	return;
}

// Simple multiplication function!
void simple_mul(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]) {
	
	//Check if the matrices are fit for multiplication 
	// Variable decleration
	int a_row = 0;
	int a_col = 0;
	int b_row = 0;
	int b_col = 0;
	int c_row = 0;
	int c_col = 0;

	// Emtying matrix c so no previous data inside
	clear_max(c);


	//Only for check
	int a_rows = 0;
	int a_cols = 0;
	int b_rows = 0;
	int b_cols = 0;

	get_Max_Size(a, &a_rows, &a_cols);
	get_Max_Size(a, &b_rows, &b_cols);

	// Check will be performed
	if (a_rows == b_rows && a_cols == b_rows) {								// In case fit for multiplication 
		// N^3 process hence 3 loops
		while (a[a_row][a_col] != NULL) {
			while (b[b_row][b_col] != NULL) {
				while (a[a_row][a_col] != NULL) {

					// Multiply each element in the row of first with consecutive collum of second!
					c[c_row][c_col] += a[a_row][a_col] * b[b_row][b_col];
					a_col++;
					b_row++;
				}

				// Increment the colum of matrix B and perform the above loop again!!
				b_col++;
				a_col = 0;
				b_row = 0;
				c_col++;		// Increment the column of C=result matrix for result storage
			}
			// Increment the row of Matrix A and perform the above 2 loops again!
			a_row++;
			c_row++; // Incrementing the row of matrix c for storage 
			c_col = 0;
			b_col = 0;
			a_col = 0;
			b_row = 0;
		}
		return;
	}
	else {
		printf("The arrays cannot be multiplied because of wrong formats!");
	}

}


// This function clears the matrix and replaces each element with a zero.
// Only the elements which have a value are replaced. The elements with NULL elements are not cleared!
int clear_max(int max_to_be_cleared[MAX_COL][MAX_COL]) {
	int i = 0;
	int j = 0;
	
	while (max_to_be_cleared[i][j]) {
		while (max_to_be_cleared[i][j]) {
			max_to_be_cleared[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return 0;
}

