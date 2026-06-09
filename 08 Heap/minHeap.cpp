#include<stdio.h>
#include<string.h>

int minHeap[100];
char itemName[100][30];

int dataCount = 1;

int getParentIndex(int index){
	return index/2;
}

int getLeftIndex(int index){
	return index*2;	
}

int getRightIndex(int index){
	return index*2+1;
}

void viewHeap(){
	if(dataCount <= 1){
		printf("Your heap is empty. Insert more data!\n\n");
	}
	else{
		for(int i=1 ; i<dataCount ; i++){
			printf("Heap[%d] = %d - %s\n", i, minHeap[i], itemName[i]);
		}
		puts("");
	}
}

void swapValue(int parentIndex, int currIdx){
	int temp = minHeap[parentIndex];
	minHeap[parentIndex] = minHeap[currIdx];
	minHeap[currIdx] = temp;
	
	char tempString[30];
	strcpy(tempString, itemName[parentIndex]);
	strcpy(itemName[parentIndex], itemName[currIdx]);
	strcpy(itemName[currIdx], tempString);
}

void upheap(int idx){
	// if root is reached, then terminate upheap
	if(idx <=1) return;
	// get parent index
	int parentIndex = getParentIndex(idx);
	// if parent value is lower than child value, then terminate upheap
	if(minHeap[parentIndex] <= minHeap[idx]) return;
	// else, swap the parent value with child value
	swapValue(parentIndex, idx);	
	// continue uphead until root is reached
	upheap(parentIndex);
}

void push(int input, char name[]){
	// defensive guard
	if (dataCount >= 100) {
		printf("Heap Overflow!\n");
		return;
    }
	// add new value to the end of array
	minHeap[dataCount] = input;
	strcpy(itemName[dataCount], name);

	// perform uphead;
	upheap(dataCount);

	// increment data count
	dataCount++;
}

void downHeap(int idx){
	// assume the current node is the smallest one
	int smallest = idx;
	// get value of left child
	int leftValue = getLeftIndex(idx);
	// get value of right child
	int rightValue = getRightIndex(idx);
	
	// determine smallest between current node and left child
	if(leftValue < dataCount && minHeap[leftValue] < minHeap[smallest])
		smallest = leftValue;
	// determine smallest between current node and right child
	if(rightValue < dataCount && minHeap[rightValue] < minHeap[smallest])
		smallest = rightValue;	
	// if current node is still the smallest one, terminate downheap
	if(smallest == idx) return;
	swapValue(smallest, idx);
	downHeap(smallest);
}

int pop(){
	// defensive guard
	if (dataCount <= 1) return -1;

	int removed = minHeap[1];
	swapValue(1, dataCount-1);
	dataCount--;
	downHeap(1);
	return removed;
}

void createMenu(){
	printf("1. Insert\n");
	printf("2. Delete \n");
	printf("3. Exit\n");
}

int main(){
	int arrData[] = {100, 18, 22, 34, 88, 55, 69, 76, 10, 5};
	char itemList[][30] = {"Coffee", "Microphone", "Marker", "Mouse", "PC", "Remote Control", "Web Cams", 
	"Chair","Table","Monitor"};

	for(int i=0 ; i<10 ; i++){
		push(arrData[i], itemList[i]);
	}

	int input = -1, num;
	char name[30];

	do{
		// printf("DATA:\n", dataCount);
		viewHeap();
		createMenu();
		do{
			printf("Input your choice: ");
			scanf("%d", &input); getchar();
		}while(input < 1 || input > 3);
		
		switch(input){
			case 1	: 	printf("What data should be inputted into the heap? ");
						scanf("%d", &num); getchar();
	
						printf("What item name should be inputted into the heap? ");
						scanf("%[^\n]", name); getchar();
	
						push(num, name);
						printf("%d %s has been inserted into the heap\n\n", num, name);
						// getchar();
						break;

			case 2	: 	if(dataCount <= 1){
							printf("Your heap is empty. Insert more data!\n\n");
						}
						else{
							printf("%d has been deleted\n\n", pop());
						}
						// getchar();
						break;
		}
	}while(input != 3);
}