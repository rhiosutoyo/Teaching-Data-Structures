#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Standard CP Stack Node
struct Book {
    char name[55];
    struct Book *next;
};

struct Book *head = NULL;

void push(char name[]) {
    struct Book *newNode = (struct Book*)malloc(sizeof(struct Book));
    if (!newNode) return;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void pop() {
    if (head == NULL) return;
    struct Book *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("EMPTY\n");
        return;
    }
    struct Book *curr = head;
    while (curr != NULL) {
        printf("%s%s", curr->name, (curr->next ? ", " : ""));
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        int op;
        scanf("%d", &op);
        
        if (op == 1) {
            char bookName[55];
            // " %50[^\n]" skips leading whitespace and reads up to 50 chars until newline
            scanf(" %50[^\n]", bookName);
            push(bookName);
        } 
        else if (op == 2) {
            pop();
        } 
        else if (op == 3) {
            display();
        }
    }

    // Clean up memory before exiting
    while (head != NULL) pop();

    return 0;
}