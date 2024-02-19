#include<stdio.h>

int main(){
	int a = 10;

	// Pointer is a data type whose value refers to another value stored  elsewhere in computer memory using its address
	// Below, we declare pointer to an integer and assign its value to the address of another variable
	int *pa = &a;
	int **ppa = &pa;

	// a
	printf("Detail of a\n");
	printf("Value	: %d\n", a);
	printf("Address	: %d\n", &a);
	printf("Size	: %d\n", sizeof(a));
		
	puts("\n");
	
	// *pa
	printf("Detail of *pa\n");
	printf("Value			: %d\n", pa);
	printf("Address			: %d\n", &pa);
	printf("Size			: %d\n", sizeof(pa));
	*pa = 89;
	printf("Reference Value		: %d\n", *pa);
	
	puts("\n");
	
	// **pa
	printf("Detail of **ppa\n");
	printf("Value			: %d\n", ppa);
	printf("Address	 		: %d\n", &ppa);
	printf("Size			: %d\n", sizeof(ppa));
    **ppa = 77;	
	printf("Reference Value		: %d\n", **ppa);

	// *(*ppa) = (*pa) = a
	
	return 0;
}

