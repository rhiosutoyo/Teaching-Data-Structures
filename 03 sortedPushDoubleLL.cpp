#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	int number;
	char name[20];
	struct data *next;
	struct data *prev;
}*head, *tail, *curr;

void printMenu(int countData){
	printf("MENU\n");
	printf("1. Push Data\n");
	printf("2. View Data\n");
	printf("3. Clear Data\n");
	printf("4. Exit Program\n");
	printf("Total data in Linked-List: %d\n", countData);
	printf("Choose your option [1..4]: ");
}

void pushSorted(int number, char name[]){
	struct data *newNode = (struct data*) malloc(sizeof(struct data));
	newNode->number = number;
	strcpy(newNode->name, name);
	
	// IF THE LINKED LIST IS STILL EMPTY
	if(head == NULL){
		head = tail = newNode;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{

		// FIND A LOCATION FOR OUR NEW NODE 
		curr = head;
		//while(curr->number < newNode->number){
		while(strcmp(curr->name, newNode->name) <= 0){	// FOR A - Z or ASCENDING
			//printf("ganteng\n");
			curr = curr-> next;
			if(curr == NULL) break;
		}

		// PUSH FRONT IF THE CURR IS STILL IN THE HEAD
		if(curr == head){
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			head->prev = NULL;	
		}
		// PUSH BACK IF THE CURR IS NULL
		else if(curr == NULL){
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			tail->next = NULL;
		}
		// PUSH IN THE MIDDLE
		else{
			curr->prev->next = newNode;
			newNode->prev = curr->prev;
			newNode->next = curr;
			curr->prev = newNode;
		}
	}
}

void viewData(){
	printf("\nYOUR DATA:\n");
	curr = head;	
	while(curr != NULL){
		printf("%d - %s\n", curr->number, curr->name);
		curr = curr->next;
	}
	printf("\n");
}

void viewDataReverse(){
	printf("\nYOUR DATA IN REVERSE ORDER:\n");
	curr = tail;	
	while(curr != NULL){
		printf("%d - %s\n", curr->number, curr->name);
		curr = curr->prev;
	}
	printf("\n");
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
	char name[20];
	do{
		// any syntax that we want to loop here
		printMenu(countData);
		scanf("%d", &input);
		
		switch(input){
			//  Push Data
			case 1	: 	printf("Please input your number: ");
						scanf("%d", &number); getchar();
						printf("Please input your name: ");
						scanf("%[^\n]", &name);
						pushSorted(number, name);
						countData++;
						break;
			// View Data
			case 2	: 	if(countData == 0) printf("\nTHERE IS NO DATA!!\n");
						else {
							viewData();
							viewDataReverse();
						}
						break;
			// Clear Data	
			case 3	:	if(countData == 0) printf("\nTHERE IS NO DATA!!\n");
						else {
							clearData();
							countData = 0;
							printf("\nYOUR DATA IN THE LINKED LIST IS CLEARED!\n");
						}
						break;	
		}		
		printf("\n");
	}while(input != 4);	
	return (0);
}
