#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Books{
	char name[100];
	struct Books *next, *prev;
}*head, *tail, *curr;

void printMenu(){
	printf("1. Add books to the shelf\n");
	printf("2. Removing books from the shelf\n");
	printf("3. View stacks\n");
	printf("4. EXIT\n");	
}

void pushFront(char name[]){
	struct Books *newNode = (struct Books*) malloc(sizeof(struct Books));
	strcpy(newNode->name, name);

	if(head == NULL){
		newNode->next = NULL;
		newNode->prev = NULL;
		head = tail = newNode;		
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		head->prev = NULL;		
	}	
}

void deleteFront(){
	printf("\nThe book you took is %s\n", head->name);

	curr = head;		
	if(head == tail){
		free(curr);
		head = tail = NULL;
	}
	else{
		head = head->next;
		free(curr);
		head->prev = NULL;
	}
}

void inputBook(){
	int len = 0;
	char name[100];
		
	do{
		printf("Input book title[3..50]: ");
		scanf("%[^\n]", name); getchar();
		len = strlen(name);		
	}while(len<3 || len > 50);
	
	pushFront(name);
}

void viewData(int count){
	printf("\nYour book in the stacks:\n");
	curr = head;	
//	while(curr != NULL){
	for(int i=1 ; i<=count ; i++){
		printf("%d) %s\n", i, curr->name);
		curr = curr->next;
	}
//	}
}

void clearData(){
	//	printf("CASE 3 - CLEAR\n");
	while(head != NULL){
		curr = head;
		head = head->next;
		free(curr);
	}
}

int main(){
	int input = 0;
	int count = 0;
	do{
		printf("The maximum number of book is %d, the total book that can be added is %d\n", MAX_SIZE, MAX_SIZE-count);
		printMenu();
		printf("Input your choice: ");
		scanf("%d", &input); getchar();
		switch(input){
			case 1	:	if(count < MAX_SIZE){
							inputBook();
							count++;
						}
						else{
							printf("\nThe stack is at the maximum size!\n");		
						}
						break;
			case 2	: 	if(count > 0){
							deleteFront();
							count--;
						}
						else{
							printf("\nYou have no book in the stack!\n");		
						}
						break;
			case 3	: 	if(count > 0){
							viewData(count);
						}
						else{
							printf("\nYou have no book in the stack!\n");		
						}
						break;
		}
		printf("\n");
	}while(input != 4);
	clearData();

	return (0);
}
