#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Request {
    int num_priority;
    char priority_str[10];
    char order[101];
    struct Request *next, *prev;
} *front = NULL, *rear = NULL;

// Helper to convert string to numeric priority
int get_priority_val(char p[]) {
    if (strcmp(p, "HIGH") == 0) return 1;
    if (strcmp(p, "NORMAL") == 0) return 2;
    return 3; // LOW
}

void add_order(char order[], char p_str[]) {
    struct Request *newNode = (struct Request*)malloc(sizeof(struct Request));
    strcpy(newNode->order, order);
    strcpy(newNode->priority_str, p_str);
    newNode->num_priority = get_priority_val(p_str);
    newNode->next = newNode->prev = NULL;

    // Standard CP Insertion Sort into Linked List (keeps list always sorted)
    if (front == NULL || newNode->num_priority < front->num_priority) {
        newNode->next = front;
        if (front) front->prev = newNode;
        front = newNode;
        if (!rear) rear = newNode;
    } else {
        struct Request *curr = front;
        while (curr->next != NULL && curr->next->num_priority <= newNode->num_priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        if (curr->next) curr->next->prev = newNode;
        newNode->prev = curr;
        curr->next = newNode;
        if (newNode->next == NULL) rear = newNode;
    }
}

void process_order() {
    if (front == NULL) return;
    struct Request *temp = front;
    front = front->next;
    if (front) front->prev = NULL;
    else rear = NULL;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("EMPTY\n");
        return;
    }
    struct Request *curr = front;
    while (curr != NULL) {
        printf("%s %s%s", curr->priority_str, curr->order, (curr->next ? ", " : ""));
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, op;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            char p[10], name[101];
            scanf("%s %[^\n]", p, name);
            add_order(name, p);
        } else if (op == 2) {
            process_order();
        } else if (op == 3) {
            display();
        }
    }
    return 0;
}