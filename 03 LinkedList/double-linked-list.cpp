#include<stdio.h>
#include<stdlib.h>

// head is for the first node
// tail is for the last node
// curr is for the moving node

struct data{
	int number;
	struct data *next;
	struct data *prev;
}*head, *tail, *curr;

void printMenu(int countData){
	printf("1. Push Data\n");
	printf("2. View Data\n");
	printf("3. Clear Data\n");
	printf("4. Exit Program\n");
	printf("Total data in Linked-List: %d\n", countData);
	printf("Choose your option [1..4]: ");
}

void pushFront(int number){
	// 1a
	struct data *newNode = (struct data*) malloc(sizeof(struct data));
	// 1b
	newNode->number = number;
	// 1c if the ll is still empty	
	if(head == NULL){
		newNode->next = NULL;
		newNode->prev = NULL;
		head = tail = newNode;		
	}
	// 1d pushFront
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		head->prev = NULL;		
	}	
}

void viewData(){
	printf("\n\nYOUR DATA:\n");
	curr = head;	
	while(curr != NULL){
		printf("%6d", curr->number);
		curr = curr->next;
	}
	printf("\n\n");
}

void viewDataReverse(){
	printf("\n\nYOUR DATA IN REVERSE ORDER:\n");
	curr = tail;	
	while(curr != NULL){
		printf("%6d", curr->number);
		curr = curr->prev;
	}
	printf("\n\n");
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
	int number = 0;
	int countData = 0;
	do{
		// any syntax that we want to loop here
		printMenu(countData);
		scanf("%d", &input);
		
		switch(input){
			//  Push Data
			case 1	: 	printf("Please input your number: ");
						scanf("%d", &number);
						pushFront(number);
						countData++;
						break;
			// View Data
			case 2	: 	if(countData == 0) printf("\nTHERE IS NO DATA!!\n\n");
						else {
							viewData();
							viewDataReverse();
						}
						break;
			// Clear Data	
			case 3	:	if(countData == 0) printf("\nTHERE IS NO DATA!!\n\n");
						else {
							clearData();
							countData = 0;
							printf("\nYOUR DATA IN THE LINKED LIST IS CLEARED!\n\n");
						}
						break;	
		}		
	}while(input != 4);	
	return (0);
}
