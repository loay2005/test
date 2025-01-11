#include <iostream>
using namespace std;

#define MAX 10
#define EMPTY -1  // when index = -1 that means its empty so i did that (lil help from gpt )

void initializeTable(int table[]) {
    for (int i = 0; i < MAX; i++) {
        table[i] = EMPTY;  // Initialize all slots as empty 
    }
}
//the hash function 
void hashing(int table[], int id) {
    int hashv = id % MAX;

    // Linear probing for collision 
    while (table[hashv] != EMPTY)
    {
        hashv = (hashv + 1) % MAX;
    }

    table[hashv] = id;  // Store ID in the available slot
}
//test the hashing 
void display(int table[]) {
    cout << "Index | Value\n";
    cout << "----------------\n";
    for (int i = 0; i < MAX; i++) {
        if (table[i] == EMPTY)
            cout << "  " << i << "   |  EMPTY\n";
        else
            cout << "  " << i << "   |   " << table[i] << "\n";
    }
}

int main() {
    int hashTable[MAX];
    initializeTable(hashTable);

    // Insert values
    int values[] = { 15, 25, 35, 20, 30, 40 };
    for (int id : values) {
        hashing(hashTable, id);
    }

    // Display final hash table
    display(hashTable);

    return 0;
}
//ana 3m el kol 
