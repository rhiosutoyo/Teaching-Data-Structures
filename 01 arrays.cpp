#include<stdio.h>

int main(){
	// initialize the array 
	int n[10] = {12, 13, 17, 20, 21};

	// assigning the array from index 5 - 9
	for(int i=5 ; i<10 ; i++){
//		n[i] = 99;
		*(n+i) = 88;
	}

	// print the array
	for(int i=0 ; i<10 ; i++){
		printf("%d = %d\n", i, n[i]);
	}
	puts("");
	
	// input / change the value of the array
	n[0] = 188;
	*(n+1) = 200;

	// print the array
	for(int i=0 ; i<10 ; i++){
		printf("%d = %d\n", i, n[i]);
	}
	puts("");

	// traversal / searching (e.g., sequential search)
	// find a value in our array
	int key = 0;
	printf("input your search key: ");
	scanf("%d", &key);
	
	int i = 0;
	int flag = -1;
	do{
		if(n[i] == key){
			flag = 1;
			printf("the value %d is located in index %d\n", key, i);
		}
		i++;
	}while( i<10 );
	if(flag == -1) printf("the value %d is not located in the array\n", key);
	return 0;
}

