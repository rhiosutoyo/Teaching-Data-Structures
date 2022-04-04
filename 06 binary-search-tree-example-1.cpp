#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};


struct node *successor(struct node *root) {
	// di subtree kanan, ambil nilai terkecil
	
	struct node *cur = root->right;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

struct node *predecessor(struct node *root) {
	// di subtree kiri, ambil nilai terbesar
	
	struct node *cur = root->left;
	while(cur->right != NULL) {
		cur = cur->right;
	}
	return cur;
}


struct node *newNode(int x) {
	struct node *curNewNode =
			(struct node*)malloc(sizeof(struct node));
			
	curNewNode->key = x;
	curNewNode->left = NULL;
	curNewNode->right = NULL;
	
	return curNewNode;
}

struct node *insert(struct node *root, int value) {
	if (root == NULL) return newNode(value);
	else if (value < root->key) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
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
	root = insert(root, 15);
	root = insert(root, 3);
	root = insert(root, 12);
	root = insert(root, 8);
	root = insert(root, 19);
	
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
