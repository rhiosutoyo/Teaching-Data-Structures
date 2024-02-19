#include<stdio.h>

void printArray(int n[]){
	for(int i=0 ; i<10 ; i++){
		printf("%d = %d\n", i, n[i]);
	}	
	puts("");
}

int searchKey(int n[], int key){
	for(int i=0 ; i<10 ; i++){
		if(n[i] == key) return i;
	}
	return -1;
}

int main(){
	// Array: 	A linear list is an elementary abstract data type that allows storage of 
	// 			elements of the same data type in the same contiguous memory area.
	
	// initialize the array 
	int n[10] = {12, 13, 17, 20, 21};

	// assigning the array from index 5 - 9
	for(int i=5 ; i<10 ; i++){
//		n[i] = 99 + i;
		*(n+i) = 99 + i;				// another way to assign a value using a pointer symbol
	}

	// print the array
//	printArray(n);
	printArray(&n[0]);
	
	// input / change the value of the array
	n[0] = 188;
	*(n+1) = 200;

	// print the array
	printArray(n);

	// traversal / searching (e.g., sequential search)
	// find a value in our array
	int key = 0;
	int result = 0;
	do{
		// application will exit if the user input 999
		printf("input your search key: ");
		scanf("%d", &key);
		if(key == 999) break;
		
		// call the sequential search function
		result = searchKey(n, key);
		if(result>=0) printf("the value %d is located in index %d\n\n", key, result);		
		else printf("the value %d is not located in the array\n\n", key);

	}while(key != 999);

	printf("Thank you for using this application!\n");
	return 0;
}

