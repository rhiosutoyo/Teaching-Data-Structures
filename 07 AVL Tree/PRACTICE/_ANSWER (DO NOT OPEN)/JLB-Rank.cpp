#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int val;
	int h;
	int subtree;
	char itemname[40];
	struct node *R, *L;
};

struct ans {
	int minDiff;
	struct node *ansNode;
};

int max(int a, int b){
	if(a<b) return b;
	return a;
}

int min(int a, int b){
	if(a<b) return a;
	return b;
}
int getH(struct node* curr){
	if(curr==NULL) return 0;
	return curr->h;
}

int getSub(struct node* curr){
	if(curr==NULL) return 0;
	return curr->subtree;
}

struct node* updtH(struct node* curr){
	curr->h = 1+max(getH(curr->L),getH(curr->R));
	return curr;
}

struct node* updtSub(struct node* curr){
	curr->subtree = 1+ getSub(curr->L)+getSub(curr->R);
	return curr;
}

int getBF(struct node* curr){
	return getH(curr->L) - getH(curr->R);
}

struct node* rotateLeft(struct node* y){
	struct node* x = y->R;
	struct node* t = x->L;
	
	x->L = y;
	y->R = t;
	
	y = updtH(y);
	x = updtH(x);
	
	y = updtSub(y);
	x = updtSub(x);
	
	return x;
}

struct node* rotateRight(struct node* x){
	struct node *y = x->L;
	struct node *t = y->R;
	
	y->R = x;
	x->L = t;
	
	x = updtH(x);
	y = updtH(y);
	
	x = updtSub(x);
	y = updtSub(y);
	
	return y;
}

struct node* newnode(int val, const char *itemname){
	struct node *tmp = (struct node*) malloc(sizeof(node));
	tmp->val = val;
	tmp->h = 1;
	tmp->subtree = 1;
	strcpy(tmp->itemname, itemname);
	tmp->L = tmp->R = NULL;
	return tmp;
}

struct node* rebalance(struct node* curr){
	int BF = getBF(curr);
	if(BF>1){
		if(getBF(curr->L)<0) curr->L = rotateLeft(curr->L);
		curr = rotateRight(curr);
	}
	if(BF<-1){
		if(getBF(curr->R)>0) curr->R = rotateRight(curr->R);
		curr = rotateLeft(curr);
	}
	return curr;
}

struct node* succ (struct node * curr){
	curr = curr->R;
	while(curr->L!=NULL) curr= curr->L;
	return curr;
}

struct node *insert(struct node *curr, int val, const char *itemname){
	if(curr==NULL) return newnode(val, itemname);
	if(val < curr->val) curr->L = insert(curr->L,val, itemname);
	else if(val>curr->val) curr->R = insert(curr->R,val, itemname);

	curr = updtH(curr);
	curr = updtSub(curr);
	curr = rebalance(curr);
	return curr;
}

struct node *buang(struct node *curr, int val){
	if(val < curr->val) curr->L = buang(curr->L,val);
	else if(val>curr->val) curr->R = buang(curr->R,val);
	else {
		if(curr->L == NULL && curr->R==NULL){
			free(curr);
			return NULL;
		}
		
		if(curr->L != NULL && curr->R == NULL){
			struct node * LC = curr->L;
			free(curr);
			return LC;
		}
		
		if(curr->L == NULL && curr->R != NULL){
			struct node *RC = curr->R;
			free(curr);
			return RC;
		}
		
		if(curr->L != NULL && curr->R != NULL){
			struct node *suk = succ(curr);
			curr->val = suk->val;
			strcpy(curr->itemname, suk->itemname);
			curr->R = buang(curr->R,suk->val);
		}
	}
	curr = updtH(curr);
	curr = updtSub(curr);
	curr = rebalance(curr);
	
	return curr;
}

struct node* freeall(struct node *curr){
	if(curr==NULL) return NULL;
	freeall(curr->L);
	freeall(curr->R);
	free(curr);
	return NULL;
}

bool search(struct node* curr, int val){
	if(curr==NULL) return 0;
	if(val<curr->val) return search(curr->L,val);
	else if(val>curr->val) return search(curr->R,val);
	else return 1;
}

int searchKth(struct node* curr, int val,int kt){
	
	if(curr==NULL) return kt;
//	printf("curr = %d cari = %d kt = %d\n",curr->val,val, kt);
	int now = getSub(curr->L)+1+kt;
	if(val<curr->val) return searchKth(curr->L,val,kt);
	else if(val>curr->val) return searchKth(curr->R,val,now);
	else return now-1;
}

struct node *kth(struct node* curr, int kt){
	int now = getSub(curr->L)+1;
	if(now<kt) return kth(curr->R,kt-now);
	else if(now>kt) return kth(curr->L,kt);
	else return curr;
}

int iabs(int x) {
	return (x < 0) ? -x : x;
}

struct ans searchClosest(struct node *curr, int x) {
	
	struct ans ret;
	ret.minDiff = 2147483647;
	ret.ansNode = NULL;
	if (curr == NULL) {
		return ret;
	}
	if (curr->val == x) {
		// found!
		ret.minDiff = 0;
		ret.ansNode = curr;
		return ret;
	}
	
	
	if (curr->val < x) {
		// ke kanan
		ret = searchClosest(curr->R, x);
	} else {
		ret = searchClosest(curr->L, x);
	}
	
	
	// if not, then compare...
	int currentDiff = iabs(curr->val - x);
	if (ret.minDiff > currentDiff) {
		ret.minDiff = currentDiff;
		ret.ansNode = curr;
	} else if (ret.minDiff == currentDiff) {
		if (ret.ansNode == NULL) ret.ansNode = curr;
		if (ret.ansNode->val > curr->val) {
			ret.ansNode = curr;
		}
	}
	return ret;
}

int main(){
	
	struct node *root = NULL;
	int n, dataCount = 0, tipe, x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&tipe);
		
		if (tipe == 1) {
			char str[40];
			scanf("%d %s", &x, str);
			x = -x;
			if(!search(root,x)) {
				root = insert(root, x, str);
				dataCount++;
			}
		} else if (tipe == 2) {
			scanf("%d", &x);
			x = -x;
			if(search(root,x)) {
				root = buang(root, x);
				dataCount--;
			}
		} else if (tipe == 3) {
			scanf("%d", &x);
			x = -x;
			struct ans ret = searchClosest(root, x);
			if (ret.ansNode != NULL) {
				printf("%d %s\n", -ret.ansNode->val, ret.ansNode->itemname);
			}
		} else {
			long long y;
			scanf("%d %lld", &x, &y);
			for(long long i=x; i<=y; i++) {
				if (i > dataCount) continue;
				struct node *curr = kth(root, i);
				printf("%d: %d %s\n", i, -curr->val, curr->itemname);
			}
		}
	}
	freeall(root); //yeah
	dataCount = 0;
	return 0;
}
