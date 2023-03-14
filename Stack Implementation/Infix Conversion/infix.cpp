#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 101

struct list {
	char op;
	struct list* next;
	struct list* prev;
}*head=NULL, *tail=NULL;

void push(char value) {
	struct list* node = (struct list*) malloc(sizeof(struct list));
	node->op = value;
	
	if(head == NULL) {
		head = tail = node;
		head->prev = NULL;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	
	tail->next = NULL;
}

char pop() {
	char a = 0;
	struct list *curr;
	
	if(tail != NULL) {
		curr = tail;
		a = tail->op;
		
		if(tail == head) {
			tail = head = NULL;
		}
		else {
			curr = tail;
			tail = tail->prev;
			tail->next = NULL;	
		}
		
		free(curr);
	}
	
	return a;
}

char top() {
	if(tail == NULL)
		return 0;
	else
		return tail->op;
}

void free_list() {
	struct list* curr = head;
	
	while(curr != NULL) {
		head = head->next;
		free(curr);
		curr = head;
	}
	
	head =  NULL;
}

void convert_infix_to_postfix(char* infix, char* postfix) {
	int i;
	int ctr = 0;
	char op;
	
	for(i=0; i<strlen(infix); i++) {
		if(infix[i] >= '0' && infix[i] <= '9') {
			postfix[ctr++] = infix[i];
		}
		else if(infix[i] == '(') {
			push(infix[i]);
		}
		else if(infix[i] == ')') {
			op = top();
			while(op != '(') {
				postfix[ctr++] = pop();
				op = top();
			}
			pop();
		}
		else {			
			if(tail != NULL) {
				if(infix[i] == '*' || infix[i] == '/') {
					op = top();
					while(op == '*' || op == '/') {
						postfix[ctr++] = pop();
						op = top();
					}
				}
				else {
					op = top();
					while(op != '(' && tail != NULL) {
						postfix[ctr++] = pop();
						op = top();
					}
				}
			}
			
			push(infix[i]);
		}
	}
	
	while(tail != NULL) {
		postfix[ctr++] = pop();
	}
	
	postfix[ctr++] = 0;
}

void convert_infix_to_prefix(char* infix, char* prefix) {
	int i;
	int ctr = 0;
	char op;
	
	for(i=strlen(infix)-1; i>=0; i--) {
		if(infix[i] >= '0' && infix[i] <= '9') {
			prefix[ctr++] = infix[i];
		}
		else if(infix[i] == ')') {
			push(infix[i]);
		}
		else if(infix[i] == '(') {
			op = top();
			while(op != ')') {
				prefix[ctr++] = pop();
				op = top();
			}
			pop();
		}
		else {			
			if(tail != NULL) {
				if(infix[i] == '+' || infix[i] == '-') {
					op = top();
					while(op == '*' || op == '/') {
						prefix[ctr++] = pop();
						op = top();
					}
				}
			}
			
			push(infix[i]);
		}
	}
	
	while(tail != NULL) {
		prefix[ctr++] = pop();
	}
	
	prefix[ctr++] = 0;
	
	//reverse string
	char temp[strlen(prefix)];
	strcpy(temp, prefix);
	for(i=strlen(prefix)-1, ctr=0; i>=0; i--, ctr++) {
		prefix[ctr] = temp[i];
	}
}

int main() {
	char infix[MAX_STRING];
	char postfix[MAX_STRING];
	char prefix[MAX_STRING];
	
	//strcpy(infix, "5*3/(2+3)-2*(4/2)");
	strcpy(infix, "(1-2)/3*(4+5-6/7)");
	
	convert_infix_to_postfix(infix, postfix);
	convert_infix_to_prefix(infix, prefix);
	
	printf("INFIX : %s\n", infix);
	printf("POSTFIX : %s\n", postfix);
	printf("PREFIX : %s\n", prefix);
	
	//free_list();
	return 0;
}