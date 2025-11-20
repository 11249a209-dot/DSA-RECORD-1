#include <stdio.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) { // Linear probing
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

// Display hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] -> %d\n", i, hashTable[i]);
}

int main() {
    initialize();

    int keys[] = {12, 22, 42, 17, 33};
    int n = 5;

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();

    return 0;
}
