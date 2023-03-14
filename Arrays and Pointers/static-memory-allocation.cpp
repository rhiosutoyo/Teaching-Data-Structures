#include<stdio.h>

int main(){
	// we only reserve 5 elements of integer
//	int n[5];
	int n[100];

	puts("\n");
	printf("%d\n", &n[0]);
	printf("%d\n", n);
	puts("\n");
	
	int i = 0;
	do{
		// only 5 elements of integer
		printf("input an integer value: ");
		scanf("%d", &n[i]);

		printf("%d = %d\n", i, n[i]);
		i++;
	}while(1);
	
	return 0;
}

