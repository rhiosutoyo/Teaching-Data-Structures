#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct request{
	int num_priority;
	char priority[10];
	char order[100];
	struct request *next, *prev;
}*front, *rear, *curr;

void printMenu(){
	printf("1. Give An Order\n");
	printf("2. Do An Order\n");
	printf("3. Clear All Orders\n");
	printf("4. Exit\n");
}

void sortList(){
	struct request *saveValue;
	struct request *temp;	
	curr = front;
	while(curr != NULL){
		temp = rear;
		while(temp != curr){
			if(temp->prev->num_priority > temp->num_priority){
//				printf("%s (%d) > %s (%d)\n", temp->prev->order, temp->prev->num_priority, temp->order, temp->num_priority);
				
				//saveValue = temp->prev;
				saveValue->num_priority = temp->prev->num_priority;
				strcpy(saveValue->priority, temp->prev->priority);
				strcpy(saveValue->order, temp->prev->order);

				// temp->prev = temp;
				temp->prev->num_priority = temp->num_priority;
				strcpy(temp->prev->priority, temp->priority);
				strcpy(temp->prev->order, temp->order);

				// temp = saveValue;
				temp->num_priority = saveValue->num_priority;
				strcpy(temp->priority, saveValue->priority);
				strcpy(temp->order, saveValue->order);
			}
			temp = temp->prev;
		}
		curr = curr->next;
	}
}

bool checkInputPriority(char priority[]){
	if(strcmp(priority, "LOW") == 0) return true;
	else if(strcmp(priority, "NORMAL") == 0) return true;
	else if(strcmp(priority, "HIGH") == 0) return true;
	return false;
}

void queueData(char order[], char priority[]){
	curr = (struct request*) malloc (sizeof(struct request));

	strcpy(curr->order, order);
	strcpy(curr->priority, priority);
	if(strcmp(curr->priority,"HIGH") == 0) curr->num_priority = 1;
	else if(strcmp(curr->priority,"NORMAL") == 0) curr->num_priority = 2;
	else if(strcmp(curr->priority, "LOW") == 0) curr->num_priority = 3;
	
	// if empty
	if(front == NULL){
		front = rear = curr;

		curr->next = NULL;
		curr->prev = NULL;
	}
	// if not empty
	else{
		rear->next = curr;
		curr->prev = rear;
		
		rear = rear->next;
		rear->next = NULL;
	}
}

void giveAnOrder(){
	int strlength = 0;
	char order[100], priority[100];

	do{
		printf("Input your order [10 - 20 characters]: ");
		scanf("%[^\n]", &order); getchar();
		strlength = strlen(order);
	}while(strlength < 10 || strlength > 20);

	do{	
		printf("Input your priority [LOW, NORMAL, HIGH]: ");
		scanf("%[^\n]", priority); getchar();
	}while(checkInputPriority(priority) == false);
	
	queueData(order, priority);
	printf("Your order \"%s\" with \"%s\" priority has been queued!\n\n", order, priority);
	getchar();
}

void printQueue(){
	if(front == NULL){
		printf("Orders Are Empty\n");
	}
	else{
		curr = front;
		while(curr != NULL){
			printf("%-7s %s (%d)\n", curr->priority, curr->order, curr->num_priority);
			curr = curr->next;
		}			
	}
	printf("\n");
}

void clearOrders(){
	if(front == NULL){
		printf("Orders Are Empty\n");
		getchar();
	}
	else{
		do{
			curr = front;
			front = front->next;
			free(curr);
		}while(front != NULL);
		printf("All Orders Has Been Cleared\n");
		getchar();
	}
}

void doAnOrder(){
	// THERE IS NO ORDER IN THE LIST
	if(front == NULL){
		printf("Orders Are Empty\n");
		getchar();
	}
	// THERE IS ONLY ONE ORDER IN THE LIST
	else if(front == rear){
		curr = front;
		printf("Order \"%s\" with \"%s\" has been done!\n", curr->order, curr->priority);
		front = rear = NULL;
		free(curr);
		getchar();
	}
	// THERE ARE MORE THAN ONE ORDER IN THE LIST
	else{
		curr = front;
		printf("Order \"%s\" with \"%s\" has been done!\n", curr->order, curr->priority);
		front = front->next;
		free(curr);
		getchar();
	}
}

int main(){
	// DATA AWAL
	queueData("RHIOSUTOYO1","LOW");
	queueData("RHIOSUTOYO2","LOW");
	queueData("RHIOSUTOYO3","HIGH");
	queueData("RHIOSUTOYO4","HIGH");
	queueData("RHIOSUTOYO5","NORMAL");
	queueData("RHIOSUTOYO6","NORMAL");
	//
	int input = 0;
	do{
		sortList();
		printQueue();

		printMenu();
		do{
			printf("Please input your choice: ");
			scanf("%d", &input); getchar();
			switch(input){
				case 1	: 	giveAnOrder();
							break;
				case 2	: 	doAnOrder();
							break;
				case 3	: 	clearOrders();
							break;
			}
		}while(input < 1 || input > 4);
	}while(input != 4);	
}
