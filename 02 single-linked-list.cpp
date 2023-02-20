#include<stdio.h>
#include<stdlib.h>

// the structure of the node: it has an integer value and a pointer
struct tnode{			// abstract data type
	int x;				// a value or data elements
	tnode *next;		// a pointer to the next node
}*head, *tail;

// a function to push a value to the front of the single linked list
void push_front(int value){
	// 1 create an empty node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	// 2 set the given value to the new node
	node->x = value;
	// 3a if the linked is empty	
	if(head == NULL){
		head = tail = node;
		tail->next = NULL;
	}
	// 3b if the linked list is not empty
	else{
		// 3b1 set the pointer of the new node to the current head
		node->next = head;
		// 3b2 move the head to the new node
		head = node;
	}
}

// a function to push a value to the back of the single linked list
void push_back(int value){
	// 1 create an empty node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	// 2 set the given value to the new node
	node->x = value;
	// 3a if the linked is empty	
	if(head == NULL){
		head = tail = node;
		tail->next = NULL;
	}
	// 3b if the linked list is not empty
	else{
		// 3b1 set the pointer next of tail to the new node
		tail->next = node;
		// 3b2 set a new node to become a tail
		tail = node;
		// 3b3 set the pointer next of new node (which is now tail) to NULL
		tail->next = NULL;
	}
}

void push_middle_after_given_node(int value, int searchKey){
	// 1 create an empty node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	// 2 set the given value to the new node
	node->x = value;
	// 3a if the linked is empty	
	if(head == NULL){
		head = tail = node;
		tail->next = NULL;
	}
	// 3b if the linked list is not empty
	else{
		// 3b1  move a "moving pointer" to the head
		struct tnode *curr = head;
		// 3b2 move the pointer to the next node until NULL / TAIL
		while(curr != NULL){
			 
			// 3b3 check whether the current node equal the given search key
			if(curr->x == searchKey){
				if(curr == tail){
					push_back(value);
				}
				else{
					node->next = curr->next;
					curr->next = node;
				}
				break;
			}
			// if it's not found, then move the moving pointer to the next node
			curr = curr->next;
		}
		// if the searchkey is not in the linked list
		if(curr == NULL){
			printf("Data %d is not found in the linked list\n", searchKey);
		}
	}
}

// a function to print the single linked list
void printList(){
	// 1 move a "moving pointer" to the head
	struct tnode *curr = head;
	// 2 move the pointer to the next node until NULL / TAIL
	while(curr != NULL){
		// 3 print a value in the current node
		printf("%d ", curr->x);
		curr = curr->next;
	}
}

void delete_front(){
	// if the linked list is empty
	if(head == NULL){
		printf("There is no data in the linked list!");
	}	
	// else if the linked list is not empty
	else{
		// if the linked list only have one element
		if(head == tail){
			free(head);
			free(tail);
		}
		// if the linked list have more than one element
		else{
			// 1. set a delete pointer to the head (because we want to delete front)
			struct tnode *del = head;
			// 2. move the pointer head into the next node
			head = head->next;
			// 3. free the first node (delete front)
			free(del);
		}
	}
}
void delete_back(){
	// if the linked list is empty
	if(head == NULL){
		printf("There is no data in the linked list!");
	}	
	// else if the linked list is not empty
	else{
		// if the linked list only have one element
		if(head == tail){
			free(head);
			free(tail);
		}
		// if the linked list have more than one element
		else{
			// 1. set a delete pointer to the head (because we want to delete front)
			struct tnode *del = head;
			// 2. move the del pointer to the node before the tail
			while(del->next != tail){
				del = del->next;
			}
			// 3. free the old tail, because the delete node will become the new tail
			free(tail);
			// 4. move the tail into the delete node (delete node become new tail)
			tail = del;
			// 5. set the pointer next of tail become NULL (if you dont want looping forev)
			tail->next = NULL;
		}
	}
}

void delete_node(int nodePosition){
	// if the linked list is empty
	if(head == NULL){
		printf("There is no data in the linked list!");
	}
	// else if the linked list is not empty
	else{
		// if the linked list only have one element
		if(head == tail){
			free(head);
			free(tail);
		}
		// if the linked list have more than one element
		else{
			// 1. set a delete pointer to the head (because we want to delete front)
			struct tnode *del = head;			
			// 2. move the delete node to the specific location
			// if the nodePos is 3, we move 2 times because we start at head
			for(int i=1 ; i<nodePosition ; i++){
				del = del->next;
			}
			// if the deleted node is located in the head
			if(del == head) delete_front();
			// if the deleted node is located in the tail
			else if(del == tail) delete_back();
			// if the deleted node is located in the middle
			else{
				struct tnode *before_del = head;
				while(before_del->next != del){
					before_del = before_del->next;
				}
				before_del->next = del->next;
				free(del);
			}
		}
	}	
}

int main(){
	printf("PUSH DATA\n");

	push_front(18);
	push_front(34);
	push_front(74);
	push_front(21);
	printList(); getchar();

	push_back(77);
	push_back(88);
	push_back(99);
	printList(); getchar();

	push_middle_after_given_node(999, 74);
	push_middle_after_given_node(101, 99);
	push_middle_after_given_node(199, 21);
	push_middle_after_given_node(888, 789);
	printList(); getchar();

	printf("DELETE FRONT 3 TIMES\n");
	delete_front();
	delete_front();
	delete_front();
	printList(); getchar();

	printf("DELETE BACK 3 TIMES\n");
	delete_back();
	delete_back();
	delete_back();
	printList(); getchar();

	printf("DELETE HEAD (node 1)\n");
	delete_node(1);
	printList(); getchar();

	printf("DELETE TAIL (node 3)\n");
	delete_node(3);
	printList(); getchar();

	printf("PUSH MORE DATA\n");
	push_back(74);
	push_back(21);
	push_back(188);
	printList(); getchar();

	printf("DELETE MIDDLE (node 3)\n");
	delete_node(3);
	printList(); getchar();
	
	printf("DELETE MIDDLE (node 2)\n");
	delete_node(2);
	printList(); getchar();
	
	return (0);
}
