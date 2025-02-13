#include<stdio.h>

int main(){
	int   x   = 30;
	int *px   = &x;
	int **ppx = &px;
	
	printf("value of x   = %d\n", x);
	printf("address of x = %d\n\n", &x);

	printf("value of px   = %d\n", px);
	printf("address of px = %d\n", &px);
	printf("access value of x using px    = %d\n\n", *px);
	
	printf("value of ppx   = %d\n", ppx);
	printf("address of ppx = %d\n", &ppx);
	printf("access value of x using ppx   = %d\n\n", *ppx);
	// *(*ppx) ==> *(px) ==> x

	*px = 40;
	printf("value of x   = %d\n", x);

	**ppx = 50;
	printf("value of x   = %d\n", x);
}
