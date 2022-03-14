#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 10

struct Music{
	char name[100];
	struct Music *next, *prev;
}*head, *tail, *curr;

void printMenu(){
	printf("1. Add a song to the list\n");
	printf("2. Playing a song\n");
	printf("3. View music queue\n");
	printf("4. EXIT\n");
}

void pushBack(char name[]){
	struct Music *newNode = (struct Music*)malloc(sizeof(struct Music));
	strcpy(newNode->name, name);
	
	if(head == NULL){
		newNode->next = NULL;
		newNode->prev = NULL;
		head = tail = newNode;		
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		newNode->next = NULL;
	}
}

void viewData(int count){
	printf("\nYour book in the queues:\n");
	curr = head;
	for(int i=1 ; i<=count ; i++){
		printf("%d) %s\n", i, curr->name);
		curr = curr->next;
	}
}

void inputMusic(){
	int len = 0;
	char name[100];
		
	do{
		printf("Input music name[1..50]: ");
		scanf("%[^\n]", name); getchar();
		len = strlen(name);
	}while(len<1 || len > 50);
	
	pushBack(name);
}

void clearData(){
	//	printf("CASE 3 - CLEAR\n");
	while(head != NULL){
		curr = head;
		head = head->next;
		free(curr);
	}
}

void deleteFront(){
	printf("\nThe music you played is %s\n", head->name);

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

int main(){
	int input = 0;
	int count = 0;
	do{
		printf("The maximum number of music is %d, the total book that can be added is %d\n", MAX_SIZE, MAX_SIZE-count);
		printMenu();
		printf("Input your choice: ");
		scanf("%d", &input); getchar();
		switch(input){
			case 1	:	if(count < MAX_SIZE){
							inputMusic();
							count++;
						}
						else{
							printf("\nThe queue is at the maximum size!\n");		
						}
						break;
			case 2	:	if(count > 0){
							deleteFront();
							count--;
						}
						else{
							printf("\nYou have no music in the queue!\n");		
						}
						break;
			case 3	:	if(count > 0){
							viewData(count);
						}
						else{
							printf("\nYou have no music in the queue!\n");		
						}
						break;
		}
		printf("\n");
	}while(input != 4);
	clearData();

	return (0);
}
