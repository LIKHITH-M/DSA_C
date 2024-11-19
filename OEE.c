#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate hash value using folding method
int foldingHash(const char* key, int tableSize) {
    int sum = 0, partSize = 2;
    for (int i = 0; i < strlen(key); i += partSize) {
        int part = 0;
        for (int j = 0; j < partSize && i + j < strlen(key); j++) {
            part = part * 100 + (key[i + j] - '0');
        }
        sum += part;
    }
    return sum % tableSize;
}

// Hash table structure
typedef struct {
    char** keys;
    int size;
} HashTable;

// Function to create hash table
HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->keys = (char**)calloc(size, sizeof(char*));
    table->size = size;
    return table;
}

// Function to insert key into hash table
void insertKey(HashTable* table, const char* key) {
    int index = foldingHash(key, table->size);
    table->keys[index] = strdup(key);
    printf("Key '%s' inserted at index %d.\n", key, index);
}

// Function to free hash table
void freeHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        free(table->keys[i]);
    }
    free(table->keys);
    free(table);
}

int main() {
    int tableSize = 10;
    HashTable* table = createHashTable(tableSize);

    insertKey(table, "123456");
    insertKey(table, "654321");
    insertKey(table, "111111");

    printf("\nHash Table Contents:\n");
    for (int i = 0; i < table->size; i++) {
        printf("Index %d: %s\n", i, table->keys[i] ? table->keys[i] : "[Empty]");
    }

    freeHashTable(table);
    return 0;
}
