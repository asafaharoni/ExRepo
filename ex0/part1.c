#include <stdio.h>
#include <stdlib.h>

#define SIZE_ERROR "Invalid size\n"
#define NUMBER_ERROR "Invalid number\n"

int get_array(int **input_array); /* Receive array of numbers from the user. 
	returns array size, and updates received pointer.*/
int integer_log2(int n); /*Calculates log base 2. 
	if result not integer, returns -1.*/

int main(){
	int *input_array; //Contains the numbers received
	int input_array_size; //Ammount of numbers received
	input_array_size = get_array(&input_array);
	int exponent,n;
	int accumulated_exponents=0;
	//size of 0 means there's no array to process.
	if (0 == input_array_size){
		return 0;
	}
	for (int i=0;i<input_array_size;i++){
		//Check if number is power of 2.
		n = input_array[i];
		exponent = integer_log2(n);
		if (exponent >= 0){
			accumulated_exponents += exponent; 
			printf("The number %d is a power of 2: %d = 2^%d\n",n,n,exponent);
		}
	}
	free(input_array);
	printf("Total exponent sum is %d\n",accumulated_exponents);
	return 0;
}

int integer_log2(int n){
	if (n <= 0) {
		return -1; //Negative numbers are never powers of 2.
	}
	int result = 0;
	while ((0==(n % 2)) && n > 1){
		n = n / 2; 
		result++;
	}
	if (n == 1){
		return result;
	}
	return -1;
}

int get_array(int** input_array){
	
	// Get array size
	printf("Enter size of input:\n");
	int size; 
	if (0==scanf(" %d",&size)){
		printf(SIZE_ERROR);
		return 0;
	}

	// Check validity
	if (size <= 0){
		printf(SIZE_ERROR);
		return 0;
	}
	
	// Fill array with user inputs
	*input_array = (int *)malloc(sizeof(int)*size);
	if (*input_array == NULL){
		return 0;
	}
	printf("Enter numbers:\n");
	for (int i=0;i<size;i++){
		if (!scanf(" %d",*input_array+i)){ 
			printf(NUMBER_ERROR);
			free(*input_array);
			return 0;
		}
	}
	//Success!
	return size;
}