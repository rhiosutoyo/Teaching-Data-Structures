#include<stdio.h>
#include<stdlib.h>

// AVL Node
struct node {
	int key;
	int height;
	struct node *left;
	struct node *right;
};

// maximum value
int max(int a, int b) {
	return (a > b) ? a : b;
}

// get node height
int getHeight(struct node *root) {
	if (root == NULL) return 0;
	return root->height;
}

// balance factor = left height - right height
int getBF(struct node *root) {
	if (root == NULL) return 0;

	return getHeight(root->left)
		 - getHeight(root->right);
}

// create new node
struct node *newNode(int value) {

	struct node *temp =
		(struct node*)malloc(sizeof(struct node));

	temp->key = value;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// RIGHT ROTATION
struct node *rightRotate(struct node *y) {

	/*
	        y
	       /
	      x
	       \
	        B

	    becomes

	        x
	         \
	          y
	         /
	        B
	*/

	struct node *x = y->left;
	struct node *B = x->right;

	// rotation
	x->right = y;
	y->left = B;

	// update height
	y->height = max(getHeight(y->left),
					getHeight(y->right)) + 1;

	x->height = max(getHeight(x->left),
					getHeight(x->right)) + 1;

	return x;
}

// LEFT ROTATION
struct node *leftRotate(struct node *x) {

	/*
	      x
	       \
	        y
	       /
	      B

	    becomes

	        y
	       /
	      x
	       \
	        B
	*/

	struct node *y = x->right;
	struct node *B = y->left;

	// rotation
	y->left = x;
	x->right = B;

	// update height
	x->height = max(getHeight(x->left),
					getHeight(x->right)) + 1;

	y->height = max(getHeight(y->left),
					getHeight(y->right)) + 1;

	return y;
}

// INSERT
struct node *insert(struct node *root, int value) {

	// normal BST insert
	if (root == NULL) {
		return newNode(value);
	}

	if (value < root->key) {
		root->left = insert(root->left, value);
	}
	else if (value > root->key) {
		root->right = insert(root->right, value);
	}

	// update height
	root->height =
		max(getHeight(root->left),
			getHeight(root->right)) + 1;

	// calculate balance factor
	int bf = getBF(root);

	// =====================
	// AVL ROTATION CASES
	// =====================

	// LL CASE
	if (bf > 1 && value < root->left->key) {
		return rightRotate(root);
	}

	// RR CASE
	if (bf < -1 && value > root->right->key) {
		return leftRotate(root);
	}

	// LR CASE
	if (bf > 1 && value > root->left->key) {

		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	// RL CASE
	if (bf < -1 && value < root->right->key) {

		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	return root;
}

// PREORDER
void printPreOrder(struct node *root) {

	if (root == NULL) return;

	printf("%d ", root->key);

	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main() {

	struct node *root = NULL;

	// LL CASE
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);

	printf("LL Rotation:\n");
	printPreOrder(root);
	puts("\n");

	// RR CASE
	root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);

	printf("RR Rotation:\n");
	printPreOrder(root);
	puts("\n");

	// LR CASE
	root = NULL;

	root = insert(root, 30);
	root = insert(root, 10);
	root = insert(root, 20);

	printf("LR Rotation:\n");
	printPreOrder(root);
	puts("\n");

	// RL CASE
	root = NULL;

	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 20);

	printf("RL Rotation:\n");
	printPreOrder(root);
	puts("\n");

	return 0;
}