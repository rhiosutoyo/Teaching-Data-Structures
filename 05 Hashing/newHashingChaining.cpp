#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data[101];
    struct Node *next;
};

// Global array of head and tail pointers for O(1) insertion
struct Node *heads[26] = {NULL};
struct Node *tails[26] = {NULL};

void insert(char str[]) {
    int index = tolower(str[0]) - 'a';
    if (index < 0 || index > 25) return; // Basic safety check

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;

    if (heads[index] == NULL) {
        heads[index] = tails[index] = newNode;
    } else {
        tails[index]->next = newNode;
        tails[index] = newNode;
    }
}

void display() {
    for (int i = 0; i < 26; i++) {
        if (heads[i] != NULL) {
            printf("INDEX [%d]: ", i);
            struct Node *curr = heads[i];
            while (curr != NULL) {
                printf("%s%s", curr->data, (curr->next ? " " : ""));
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        char temp[101];
        scanf(" %[^\n]", temp);
        insert(temp);
    }

    display();

    // Memory cleanup (Optional in some CP environments, but good practice)
    for (int i = 0; i < 26; i++) {
        struct Node *curr = heads[i];
        while (curr) {
            struct Node *toFree = curr;
            curr = curr->next;
            free(toFree);
        }
    }

    return 0;
}