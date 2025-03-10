#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node{
	char data[100];
	struct node *next;
}*hashTable[26], *curr;

// hashKey value will become the index in the hashTable
// data value will be stored in the hashTable
void pushBack(int hashKey, char data[]){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	// if the index is still empty
	if(hashTable[hashKey] == NULL){
		hashTable[hashKey] = newNode;
	}
	// if the index is not empty
	else{
		curr = hashTable[hashKey];
		while(curr->next != NULL) curr = curr->next;
		curr->next = newNode;
	}
}

void viewHashTable(){
	// ACCESS ALL INDEX 
	for(int i=0 ; i<26 ; i++){
		// CHECK WHETHER THE INDEX IS NULL OR NOT
		if(hashTable[i] != NULL){
			// PRINT ALL ELEMENTS / DATA IN THE INDEX
			printf("HASH TABLE INDEX [%d]:\n", i);
			curr = hashTable[i];
			while(curr != NULL){
				printf("%s ", curr->data);
				curr = curr->next;
			}
			printf("\n\n");
		}
	}
}

int hashFunction(char data[]){
	int hashKey = -1;
	char firstChar;
	// you can use method: division or mid-square or else
	// in this case, our rules is: a / A -> 0, b / B -> 1, c / C -> 2, and so on ...
	firstChar = data[0];
	hashKey = tolower(firstChar) - 97; // because ascii of a is 97	
	return hashKey;
}

int main(){
	char data[100];
	do{
		printf("Input data: ");
		scanf("%[^\n]", data); getchar();
		if(strcmpi(data, "exit") == 0) break;
		pushBack(hashFunction(data), data);
	}while(true);
	viewHashTable();
	// pop all will be here
	getchar();
}

