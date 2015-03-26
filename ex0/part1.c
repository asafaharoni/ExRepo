#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// YL: being consistent is the trademark of a good programmer. try keeping the same conventions of line breaks and spaces etc.

// YL: normally, error codes are defined as numbers in an enum and there is a functions which converts the codes to strings.
// YL: traditionally, success is 0, and errors are negative valus. easier to test and pass around.
#define SIZE_ERROR "Invalid size\n"
#define NUMBER_ERROR "Invalid number\n"

// dennis ritchie tought us that asterisks are attached to the variable name.
int get_array(int** input_array); //Receive array of numbers from the user. // YL: what does it return?
int integer_log2(int n); //Calculates log base 2. if result not integer, returns -1.

int main(){
	// YL: don't define variables of two different types in the same line, it's confusing
	int input_array_size, *input_array; //Contains the numbers received
	input_array_size = get_array(&input_array);
	int exponent,n;
	int accumulated_exponents=0;
	// YL: better to test for failure and exit immediately, less indented code. i.e. if (0 <= ...) return -1;
	// YL: generally speaking, the common/sucess branch should be indented as little as possible
	if (input_array_size > 0){
		for (int i=0;i<input_array_size;i++){
			//Check if number is power of 2.

			n = input_array[i];
			exponent = integer_log2(n);
			if (exponent > -1){
				accumulated_exponents += exponent; 
				printf("The number %d is a power of 2: %d = 2^%d\n",n,n,exponent);
			}
		}
		free(input_array);
		printf("Total exponent sum is %d\n",accumulated_exponents);
	}
	
	return 0;
}

int integer_log2(int n){
	if (n <= 0) {
		// YL: why -2? if you are indicating something, it better be done with defines in the header (what you are doing here is called 'magic values' and is frowned upon)
		return -2;
	}
	// YL: some compilers (and old standards) don't allow definition of variables in the middle of a function. better to avoid it.
	int result = 0;
	while (((n % 2) == 0) && n > 1){
		n = n / 2; 
		result++;
	}
	if (n == 1){
		return result;
	} else {
		return -1;
	}
	// YL: it's a matter of style, but i prefer that the final return will not be enclosed in 'else' clause. this way it is very is to see that the function always return a meaningfful valuee
}

int get_array(int** input_array){
	// YL: it's better to deal with errors in one place which is not part of the main flow.
	// YL: usually, you define a label of error, and uses goto to jump to that label when error occurs.
	// YL: they really don't like this in universities, becuse if Dikstra.  But this how it's done in the industry.
	
	// Get array size
	printf("Enter size of input:\n");
	// YL: var in middle of function
	int size; 
	// YL: put the constant on left hand of comparisons. it will save you onr day from mistakenly assigning instead of comparing
	if (scanf(" %d",&size)==0){
		printf(SIZE_ERROR);
		return 0;
	}

	// Check validity
	if (size<=0){
		printf(SIZE_ERROR);
		return 0;
	}
	
	// YL: comments shouldn't explain what you are doing, it's quite obvious for any reader who knows the language.
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
