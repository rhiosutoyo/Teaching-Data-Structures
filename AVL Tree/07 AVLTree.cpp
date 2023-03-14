#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	int height;
	struct node *left;
	struct node *right;
};

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

int getHeight(struct node *root) {
	if (root == NULL) return 0;
	return root->height;
}

// get balance factor
int getBF(struct node *root) {
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

struct node *rightRotate(struct node *y) {
	struct node *x = y->left;
	struct node *B = x->right;
	
	// rotate
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct node *leftRotate(struct node *x) {
	struct node *y = x->right;
	struct node *B = y->left;
	
	// rotate
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}


// di subtree kanan, ambil nilai terkecil
struct node *successor(struct node *root) {	
	struct node *cur = root->right;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

// di subtree kiri, ambil nilai terbesar
struct node *predecessor(struct node *root) {	
	struct node *cur = root->left;
	while(cur->right != NULL) {
		cur = cur->right;
	}
	return cur;
}

struct node *newNode(int x) {
	struct node *currNewNode =
			(struct node*)malloc(sizeof(struct node));
			
	currNewNode->key = x;
	currNewNode->height = 1;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	
	return currNewNode;
}

struct node *insert(struct node *root, int value) {
	if (root == NULL) return newNode(value);
	else if (value < root->key) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}

	// calcuate balance factor for each node
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bfactor = getBF(root);
		
	// if violoation, then rotate
	if (bfactor > 1 && value < root->left->key) {
		return rightRotate(root);
	}
	if (bfactor < -1 && value > root->right->key) {
		return leftRotate(root);
	}
	if (bfactor > 1 && value > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bfactor < -1 && value < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;	
}

struct node *deleteValue(struct node *root, int value) {
	if (root == NULL) return NULL; // tidak ketemu...
	if (value < root->key) {
		root->left = deleteValue(root->left, value);
	} else if (value > root->key) {
		root->right = deleteValue(root->right, value);
	} else {
		
		// ketemu. mari kita mulai delete...
		
		// case 1 : tidak punya anak
		// case 2 : hanya punya anak kiri
		// case 3 : hanya punya anak kanan
		if ((root->left == NULL) || (root->right == NULL)) {
			
			struct node *temp = NULL;
			if (root->left != NULL) temp = root->left;
			else temp = root->right;
			
			if (temp == NULL) {
				// pasti tidak punya anak
				// ini adalah case 1
				temp = root;
				root = NULL;
			} else {
				// ini adalah case 2 dan case 3
				*root = *temp;
			}
			free(temp);
			
		} else {
			// ini case ke 4
			// ada 2 anak, maka kita ambil suksesor/predesesor
			// terserah
			
			struct node *temp = predecessor(root);
			root->key = temp->key;
			
			// delete
			root->left = deleteValue(root->left, temp->key);
		}
	}

	if (root == NULL) return root;
	
	// Kita perlu fix height dlsbnya
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bfactor = getBF(root);
	
	if (bfactor > 1 && getBF(root->left) >= 0) {
		return rightRotate(root);
	}
	if (bfactor > 1 && getBF(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bfactor < -1 && getBF(root->right) <= 0) {
		return leftRotate(root);
	}
	if (bfactor < -1 && getBF(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}


void printAll(struct node *root) {
	if (root == NULL) return;
	printAll(root->left);
	printf(" %d ", root->key);
	printAll(root->right);
}

struct node *freeAll(struct node *root) {
	if (root == NULL) return NULL;
	root->left = freeAll(root->left);
	root->right = freeAll(root->right);
	free(root);
	return NULL;
}

int main() {
	struct node *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 17);
	
	printAll(root);
	puts("");
	
	root = deleteValue(root, 10);
	
	printAll(root);
	puts("");
	
	root = deleteValue(root, 15);
	
	printAll(root);
	puts("");
	
	root = freeAll(root);
	
	return 0;
}
