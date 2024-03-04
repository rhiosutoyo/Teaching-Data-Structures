#include<stdio.h>

int arrHeap[100];
int nelement = 0;

int getMin() {
	if (nelement == 0) {
		printf("HEAP MASIH KOSONG!\n");
		return 0;
	}
	return arrHeap[1];
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void downHeap(int idx) {
	int toIdx = idx;
	if (2*idx <= nelement && arrHeap[idx] > arrHeap[2*idx]) {
		toIdx = 2*idx;
	}
	if (2*idx+1 <= nelement && arrHeap[toIdx] > arrHeap[2*idx+1]) {
		toIdx = 2*idx+1;
	}
	if (idx == toIdx) return;
	swap(&arrHeap[idx], &arrHeap[toIdx]);
	downHeap(toIdx);
}

// intinya, delete yang paling kecil
int extractMin() {
	if (nelement == 0) {
		printf("HEAP SUDAH KOSONG!\n");
		return 0;
	}
	
	if (nelement == 1) {
		nelement--;
		return arrHeap[1];
	}
	
	int returnValue = arrHeap[1];
	
	swap(&arrHeap[1], &arrHeap[nelement]);
	nelement--;
	
	downHeap(1);
	return returnValue;
}

void upHeap(int idx) {
	if (idx == 1) return;
	
	int parentIdx = idx / 2;
	
	if (arrHeap[idx] < arrHeap[parentIdx]) {
		swap(&arrHeap[idx], &arrHeap[parentIdx]);
		upHeap(parentIdx);
	}
}

void insertHeap(int x) {
	nelement++;
	arrHeap[nelement] = x;
	upHeap(nelement);
}

void makeHeap() {
	// kalau sudah ada element2nya di array
	// maka panggil ini, biar arraynya jadi heap
	for(int i=nelement/2; i>0; i--) {
		downHeap(i);
	}
}

int main() {
	
	insertHeap(85);
	insertHeap(64);
	insertHeap(100);
	
	insertHeap(5);
	insertHeap(9);
	insertHeap(120);
	insertHeap(70);
	
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	printf("%d\n", extractMin());
	
	
	return 0;
}
