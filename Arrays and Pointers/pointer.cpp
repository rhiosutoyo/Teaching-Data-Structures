#include<stdio.h>

int main(){
	int a = 10;
	int *pa = &a;
	int **ppa = &pa;

	// a
	printf("Detail of a\n");
	printf("Value	: %d\n", a);
	printf("Address	: %d\n", &a);
	printf("Size	: %d\n", sizeof(a));
	*pa = 89;
		
	puts("\n");
	
	// *pa
	printf("Detail of *pa\n");
	printf("Value			: %d\n", pa);
	printf("Address			: %d\n", &pa);
	printf("Size			: %d\n", sizeof(pa));
	printf("Reference Value		: %d\n", *pa);
    **ppa = 77;	
	
	puts("\n");
	
	// **pa
	printf("Detail of **ppa\n");
	printf("Value			: %d\n", ppa);
	printf("Address	 		: %d\n", &ppa);
	printf("Size			: %d\n", sizeof(ppa));
	printf("Reference Value		: %d\n", **ppa);
	// *(*ppa) = (*pa) = a
	
	return 0;
}

