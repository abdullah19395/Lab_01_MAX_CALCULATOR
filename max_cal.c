#include <stdio.h>



// Max matrix size
#define MAX_COL 50

//Function declerations
void parse_file(int a[MAX_COL][MAX_COL][MAX_COL]);
int size_chk(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int type);
void parse_array(int main_array[MAX_COL][MAX_COL][MAX_COL], int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int num_a, int num_b);
void subtract(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
void addition(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
void unit_test_add(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void print_array(int temp_res[MAX_COL][MAX_COL]);
void unit_test_sub(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void multiply_strasson(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
void simple_mul(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);

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
	printf("Here is the multiplication of a with b \n");
	simple_mul(a, b, c);
	print_array(c);
	getchar();
	return 1;
}


/*
Here is the size checker
This will check the array size and compare the two arrays
If the arrays are fit for addition it will add else return 1;
Similarly the same function will be used for testing if the arrays are fit for subtraction
and multiplication!*/

int size_chk(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int type) {
	int i = 0;
	int j = 0;
	int a_cols = 0;
	int a_rows = 0;
	int b_cols = 0;
	int b_rows = 0;

	// Simply goto the end of the array col wise and add cols
	while (a[i][j] != NULL) {
		a_cols++;
		j++;
	}
	j = 0;
	// Simply goto the end of the array row wise and add rows
	while (a[i][j] != NULL) {
		a_rows++;
		i++;
	}
	i = 0;

	while (b[i][j] != NULL) {
		b_cols++;
		j++;
	}
	j = 0;
	while (b[i][j] != NULL) {
		b_rows++;
		i++;
	}

	if (type == 0) { 	// check for addition and subtraction
		if (a_rows == b_rows && a_cols == b_cols)
		{
			return 0;
		}
		else
			return 1;
	}
	else {
		// Check for multiplication!
		//The number of columns of the 1st matrix must equal the number of rows of the 2nd matrix.
		if (a_cols == b_rows) {
			return 0;
		}
		else {
			return 1;
		}
	}
}


/*void size_make(int a[][][]){
int row_cols_a = 0;
if (sizeof(a)==size)

if (size of(b) % 8 == 0 ){
row_cols_a = size of(a) / 8;
}
}*/

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
	int check = size_chk(a, b, 0);
	if (check == 0) {
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
	int check = size_chk(a, b, 0);
	if (check == 0) {
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

void max_computer(void) {


}

void unit_test_add(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the addition test");
	// Parse arrays from file
	parse_array(main_array, temp_a, temp_b, 0, 1);
	// Add the arrays
	addition(temp_a, temp_b, temp_res);
	
	print_array(temp_res);
	return;
}


void unit_test_sub(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the subtraction test");
	parse_array(main_array, temp_a, temp_b, 0, 1);
	subtract(temp_a, temp_b, temp_res);
	print_array(temp_res);
	return;
}


void unit_test_multiply(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]) {
	printf("Here is the Multiplication test");
	parse_array(main_array, temp_a, temp_b, 0, 1);
	subtract(temp_a, temp_b, temp_res);
	print_array(temp_res);
	return;
}

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

void simple_mul(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]) {
	int check = size_chk(a, b, 1);
	int a_row = 0;
	int a_col = 0;
	int b_row = 0;
	int b_col = 0;
	int c_row = 0;
	int c_col = 0;

	if (check == 0) {
		while (a[a_row][a_col] != NULL) {
			while (b[b_row][b_col] != NULL) {
				c[c_row][c_col] = (a[a_row][a_col] * b[b_row][b_col]) + (a[a_row][a_col + 1] * b[b_row + 1][b_col]) + (a[a_row][a_col + 2] * b[b_row + 2][b_col]);
				b_col++;
				c_col++;
			}
			c_col = 0;
			b_col = 0;
			a_row++;
			c_row++;
		}
	}
	else {
		printf("The arrays cannot be multiplied because of wrong formats!");
	}

}


