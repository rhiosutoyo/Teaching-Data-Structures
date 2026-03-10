#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Music {
    char name[55];
    struct Music *next;
};

// Queue pointers for O(1) Push and Pop
struct Music *head = NULL, *tail = NULL;

void pushBack(char name[]) {
    struct Music *newNode = (struct Music*)malloc(sizeof(struct Music));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void popFront() {
    if (head == NULL) return;
    struct Music *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL; // Queue becomes empty
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("EMPTY\n");
        return;
    }
    struct Music *curr = head;
    while (curr != NULL) {
        printf("%s%s", curr->name, (curr->next ? ", " : ""));
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
            char songName[55];
            scanf(" %[^\n]", songName);
            pushBack(songName);
        } else if (op == 2) {
            popFront();
        } else if (op == 3) {
            display();
        }
    }

    // Cleanup
    while (head != NULL) popFront();

    return 0;
}