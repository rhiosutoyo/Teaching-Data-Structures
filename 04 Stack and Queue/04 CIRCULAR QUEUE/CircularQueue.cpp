#include<stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;
int menu;

int checkFull(){
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1) ) return 1;
    return 0;
}

int checkEmpty(){
    if(front == -1) return 1;
    return 0;
}

void addQueue(int num){
    if(checkFull()){
        printf("\nThe queue is full.");
    }else{
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = num;
        printf("\nInserted : %d", num);
    }
}

int removeQueue(){
    int num;
    if(checkEmpty()){
        printf("\nThe queue is empty!");
        return -1;
    }else {
        num = items[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else front = (front + 1) % SIZE;

        printf("\nDeleted : %d\n", num);
        return num;
    }
}

void showQueue(){
    int i;
    if (checkEmpty())
        printf(" \n Empty Queue\n");
    else {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

void insert(){
	int i = 0;
	int n;
	char y;
	while(i <= 5){
		printf("\nInsert a number :");
		scanf("\%d", &n);
		addQueue(n);
		i++;
	}
}

int main(){
    do{
        printf("\nCircular Queue");
        printf("\n===============");
        printf("\n1. Add Queue");
        printf("\n2. Remove Queue");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nChoose : ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
            insert();
            break;
            case 2:
            removeQueue();
            break;
            case 3:
            showQueue();
            break;
            default: printf("\nWrong Choice!");
            
        }
        
        
    }while (menu != 4);
    


    return 0;
}
