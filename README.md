//Function declerations


This file is used to parse the array form the text filee 
void parse_file(int a[MAX_COL][MAX_COL][MAX_COL]);

This function compares the sizes of two arrays and depending on type of test results 0 for correct and 1 for wrong
	1 type for multiplication
	0 type for addition/subtraction
int size_chk(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int type);

// This function parse the MAX from the file. User can spacify in the num_a and num_b for the MAX numbers he wants to pick!
void parse_array(int main_array[MAX_COL][MAX_COL][MAX_COL], int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int num_a, int num_b);

// Subtracts MAX b from MAX a;
void subtract(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);

// Adds array a into MAX b and generates result c
void addition(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
void unit_test_add(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void print_array(int temp_res[MAX_COL][MAX_COL]);
void unit_test_sub(int main_array[MAX_COL][MAX_COL][MAX_COL], int temp_res[MAX_COL][MAX_COL], int temp_a[MAX_COL][MAX_COL], int temp_b[MAX_COL][MAX_COL]);
void multiply_strasson(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);
void simple_mul(int a[MAX_COL][MAX_COL], int b[MAX_COL][MAX_COL], int c[MAX_COL][MAX_COL]);




