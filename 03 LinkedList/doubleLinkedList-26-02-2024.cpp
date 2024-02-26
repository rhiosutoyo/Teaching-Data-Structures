#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
	char name[100];
	int age;
	struct tnode *next;
	struct tnode *prev;
}*head, *tail, *curr;

// pushBack: push after tail
void pushBack(char name[], int age){
	// ask memory from the computer
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	// we assign the given value to the node
	strcpy(node->name, name);
	node->age = age;
	
	// if there's no data
	if(head == NULL){
		head = tail = node;
		head->prev = NULL;
		tail->next = NULL;
	}
	// if there's already existing data
	else{
		node->next = NULL;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

// pushFront: push before head
void pushFront(char name[], int age){
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	strcpy(node->name, name);
	node->age = age;
	
	// if there's no data
	if(head == NULL){
//		head = tail = node;
		head = node;
		tail = node;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		node->next = head;
		node->prev = NULL;
		head->prev = node;
		head = node;
	}
}

void printAll(){
	curr = head;
	while(curr != NULL){
		printf("Name: %s\n", curr->name);
		printf("Age : %d\n\n", curr->age);
		curr = curr->next;
	}
}

void pushSorted(char name[], int age){
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	strcpy(node->name, name);
	node->age = age;
	
	// there's no data
	if(head == NULL){
		head = tail = node;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		// find location for the curr;
		curr = head;
		while(curr != NULL){
			if(curr->age > node->age) break;
			curr = curr->next;
		}
		
		// this happen if node value is 20, and head value is 30
		if(curr == head){
			pushFront(name, age);
		}
		// this happen if node value is 50, and tail value is 40 		
		else if(curr == NULL){
			pushBack(name, age);
		}
		// this happen if the node value is between 30 to 40
		else{
			curr->prev->next = node;
			node->next = curr;
			node->prev = curr->prev;
			curr->prev = node;
		}
	}
}

void deleteNode(char name[]){
	// if the linked list is empty
	if(head == NULL){
		printf("The Linked List is empty!!\n");
	}
	// more than one node
	else{
		curr = head;
		// find the location of the node to be deleted
		while(curr!=NULL){
			if(strcmp(curr->name,name) == 0) break;
			curr = curr->next;
		}
		// NOT FOUND
		if(curr == NULL){
			printf("The %s is not located in the linked list!!\n", name);
		}
		// FOUND
		else{
			// there is only one node
			if(head == tail){
				free(head);
				head = tail = NULL;
			}
			// FIRST NODE
			else if(curr == head){
				head = head->next;
				head->prev = NULL;
				free(curr);
			}
			// LAST NODE
			else if(curr == tail){
				tail = tail->prev;
				tail->next = NULL;
				free(curr);
			}
			// MIDDLE NODE
			else{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
			}			
		}
	}	
}

int main(){
	pushBack("Aurel", 10);
	pushBack("Nico", 20);
	pushBack("Rosaline", 30);
	pushBack("Lucas", 40);
	
	// push sorted
	pushSorted("Darren", 5);
	pushSorted("Michael", 50);
	pushSorted("Peter", 25);
	
	// delete
	deleteNode("Aurelll");
	deleteNode("Darren");
	deleteNode("Aurel");
	deleteNode("Michael");
	deleteNode("Lucas");
	deleteNode("Peter");
	deleteNode("Nico");
	deleteNode("Rosalinee");
	deleteNode("Rosaline");
	deleteNode("Rosaline");

	printAll();
	return(0);
}

