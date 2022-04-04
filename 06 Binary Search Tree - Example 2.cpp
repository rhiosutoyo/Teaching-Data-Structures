#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *left;
	struct node *right;	
};

struct node *newNode(int input){
	struct node *currNewNode = (struct node*) malloc(sizeof(struct node));
	currNewNode->value = input;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	return currNewNode;
}

// SORTED
struct node *insert(struct node *root, int input){
	// if the tree is still empty
	if(root == NULL) return newNode(input);

	// the inputted value is smaller than the root
	else if(input < root->value){
		root->left = insert(root->left, input);
	}
	
	// the inputted value is bigger than the root
	else{
		root->right = insert(root->right, input);
	}
	return root;
};

void printPrefix(struct node *root){
	if(root == NULL) return;
	printf(" %d ", root->value);
	printPrefix(root->left);
	printPrefix(root->right);
}

void printPostfix(struct node *root){
	if(root == NULL) return;
	printPostfix(root->left);
	printPostfix(root->right);
	printf(" %d ", root->value);
}

void printInfix(struct node *root){
	if(root == NULL) return;
	printInfix(root->left);
	printf(" %d ", root->value);
	printInfix(root->right);
}

struct node *predecessor(struct node *root){
	// MOVE LEFT ONCE
	struct node *curr = root->left;

	// THEN GO RIGHT UNTIL BEFORE NULL
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

struct node *deleteValue(struct node *root, int input){
	if(root == NULL) return NULL; 		// NOT FOUND
	else if(input < root->value){		// SMALLER
		root->left = deleteValue(root->left, input);
	}
	else if(input > root->value){		// BIGGER
		root->right = deleteValue(root->right, input);
	}
	else{								// FOUND
		// 1 DON'T HAVE CHILDREN
		// 2 ONLY HAVE LEFT CHILD
		// 3 ONLY HAVE RIGHT CHILD
		if( (root->left == NULL) || (root->right == NULL) ){
			struct node *temp = NULL;
			
			// PICK EITHER LEFT CHILD OR RIGHT CHILD
			if(root->left != NULL) temp = root->left;
			else temp = root->right;
			
			// CASE 1
			if(temp == NULL){
				temp = root;		// we change the address
				root = NULL;				
			}
			// CASE 2 / CASE 3
			else{
				*root = *temp;		// only change the value
			}
			free(temp);
		}
		// IF BOTH CHILDREN ARE EXISTS
		else{
			// FIND MY PREDECESSOR
			struct node *temp = predecessor(root);
			
			// SET VALUE OF ROOT WITH ITS PREDECESSOR
			root->value = temp->value;

			// DELETE NODE
			root->left = deleteValue(root->left, temp->value);
		}
	}
	return root;
}

void printBST(struct node *root){
	printf("INFIX:\n");
	printInfix(root);puts("");
	printf("PREFIX:\n");
	printPrefix(root);puts("");
	printf("POSFIX:\n");
	printPostfix(root);puts("");puts("");
}

void printMenu(){
	printf("MENU\n");
	printf("1. Add Value to Binary Search Tree\n");
	printf("2. Delete Value to Binary Search Tree\n");
	printf("3. Exit Program\n");
}

int main(){	
	struct node *root = NULL;
	
	// INITIAL DATA
	int initialData[8] = {15,10,20,13,8,22,18,17};
	for(int i=0 ; i<8 ; i++) {
		root = insert(root, initialData[i]);	
	}

	// START MENU
	int input = 0;
	int value = 0;
	do{
		printBST(root);
		printMenu();
		printf("Input Your Choice: "); scanf("%d", &input);
		switch(input){
			case 1	:	printf("Input your value: ");
						scanf("%d", &value); 
						root = insert(root, value);
						break;
			case 2	:	printf("What value that you want to delete: ");
						scanf("%d", &value); 
						root = deleteValue(root, value);
						break;
		}
	}while(input != 3);
	return (0);
}

