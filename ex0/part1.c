#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE_ERROR "Invalid size\n"
#define NUMBER_ERROR "Invalid number\n"

int get_array(int** input_array); //Receive array of numbers from the user. 
int integer_log2‎(int n); //Calculates log base 2. if result not integer, returns -1.

int main(){
	int input_array_size, *input_array; //Contains the numbers received 
	input_array_size = get_array(&input_array);
	int exponent;
	int n;
	if (input_array_size > 0){
		for (int i=0;i<input_array_size;i++){
			//Check if number is power of 2.
			n = input_array[i];
			exponent = integer_log2‎(n);
			if (exponent > -1){
				printf("The number %d is a power of 2: %d = 2^%d\n",n,n,exponent);
			}
			
		}
		free(input_array);
	}
	
	return 0;
}

int integer_log2‎(int n){
	if (n <= 0) {
		return -2;
	}
	
	int result = 0;
	while (((n % 2) == 0) && n > 1){
		n = n / 2; 
		result++;
	}
	if (n == 1){
		return result;
	}else{
		return -1;
	}
	
}
int get_array(int** input_array){
	// Get array size
	printf("Enter size of input:\n");
	int size; 
	if (scanf(" %d",&size)==0){
		printf(SIZE_ERROR);
		return 0;
	}

	// Check validity
	if (size<=0){
		printf(SIZE_ERROR);
		return 0;
	}
	
	// Allocate array and set input_array to point to it.
	*input_array = (int *)malloc(sizeof(int)*size);
	if (*input_array == NULL){
		return 0;
	}
	
	// Fill array with user inputs
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