#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 26

char hashTable[TABLE_SIZE][101];
int occupied[TABLE_SIZE] = {0}; // Track which slots are used
int count = 0;

void insert(char str[]) {
    if (count >= TABLE_SIZE) return; // Table is full

    int baseIndex = tolower(str[0]) - 'a';
    int i = 0;
    
    // Linear Probing logic: (base + i) % 26
    while (i < TABLE_SIZE) {
        int targetIndex = (baseIndex + i) % TABLE_SIZE;
        
        if (!occupied[targetIndex]) {
            strcpy(hashTable[targetIndex], str);
            occupied[targetIndex] = 1;
            count++;
            return;
        }
        i++; // Collision! Move to next slot
    }
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (occupied[i]) {
            printf("INDEX [%d]: %s\n", i, hashTable[i]);
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
    return 0;
}