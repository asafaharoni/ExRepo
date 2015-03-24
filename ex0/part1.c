#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE_ERROR "Invalid size\n"
#define NUM_ERROR "Invalid number\n"

int get_array(int** input_array); //Receive array of numbers from the user. 

int main(){
	int input_array_size, *input_array; //Contains the numbers received 
	input_array_size = get_array(&input_array);
	for (int i=0;i<input_array_size;i++){
		printf("%d\n", *input_array+i);
	}
	return 0;
}

int get_array(int** input_array){
	int size; 

	// Get array size
	printf("Enter size of input:\n");
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
			printf(NUM_ERROR);
			free(*input_array);
			return 0;
		}
	}
	//Success!
	return size;
}