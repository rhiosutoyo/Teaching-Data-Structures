#include<stdio.h>

// arrays --> number, string, floating numbers, features (in ML)
// create
// access
// set a value / modify
// print the array

int main(){
	// array 1D
	// create array
	int number[10] = {10, 20, 33, 40, 50};
	// access array
	// index start at 0
	printf("%d\n", number[2]); // index 2, element 3
	
	// set a value to a specific index
	number[7] = 99;
	scanf("%d", &number[9]); getchar();	
	
	// combine array with repetition
	for(int i=0; i<10 ; i++){
		printf("%d ", number[i]);
	}

	puts("");		// newline
//	printf("\n");	// can also use this

	// array with string

	// a single character
	char chr;								// character ==> 'a' / 'x' / '?' / '%'
	scanf("%c", &chr); getchar();
	printf("%c\n", chr); 

	// a string with maximum character of 100
	char string[100];						// a string	 ==> "BINUS" / "Alam Sutera" / "p4ssW0rd!"

	scanf("%s", string); getchar();			// no need to use '&' because 'string' is '&string[0]'
	printf("%s\n", string);					// one word only

	scanf("%[^\n]", string); getchar();		// scan the input buffer until we find enter (\n)
	printf("%s\n", string);					// can input sentence
	
	// 20 string with maximum character of 100
	char listofstring[20][100];		// list of string
	/*
		"Rhio Sutoyo"
		"Niko Sutiono"
		"Theo Justin"
	*/

	// to scan and print list of sentence
	for(int j=0;j<3;j++){
		scanf("%[^\n]", listofstring[j]); getchar();		// scan the input buffer until we find enter (\n)
		printf("%s\n", listofstring[j]);					// can input sentence
	}
}

