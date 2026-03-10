#include <stdio.h>
#include <stdlib.h>

int *items;
int front = -1, rear = -1, maxSize;

int isFull() {
    return ((front == 0 && rear == maxSize - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void addQueue(int num) {
    if (isFull()) return; // CP usually ignores or handles specific error codes
    if (front == -1) front = 0;
    rear = (rear + 1) % maxSize;
    items[rear] = num;
}

void removeQueue() {
    if (isEmpty()) return;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
}

void display() {
    if (isEmpty()) {
        printf("EMPTY\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d%s", items[i], (i == rear ? "" : " "));
        if (i == rear) break;
        i = (i + 1) % maxSize;
    }
    printf("\n");
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    maxSize = k;
    items = (int*)malloc(sizeof(int) * maxSize);

    while (n--) {
        int op, val;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            addQueue(val);
        } else if (op == 2) {
            removeQueue();
        } else if (op == 3) {
            display();
        }
    }

    free(items);
    return 0;
}