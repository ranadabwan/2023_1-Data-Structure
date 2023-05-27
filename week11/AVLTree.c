#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 13
#define empty(e) (strlen(e.key)==0)
#define equal(e1,e2) (!strcmp(e1.key, e2.key))

typedef struct Element {
    char key[KEY_SIZE];
}Element;

Element hashTable[TABLE_SIZE];

void initTable(Element ht[]) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) ht[i].key[0] = NULL;
}

int transform(char *key) {
    int i;
    int number = 0;
    int size = strlen(key);
    for (i=0; i<size; i++) number = number + key[i]; //ASCII 로 변환후 더하기

    return number;
}

int hashFunction(char *key) {
    return transform(key) % TABLE_SIZE;
}

void addHashTable(Element item, Element ht[]) {
    int i, hashValue;
    hashValue = hashFunction(item.key);
    i=hashValue;
    while (!empty(ht[i])) {
        if(equal(ht[i], item)) {
            printf("Duplicate insert error!\n");
            return;
        }
        i = (i+1) % TABLE_SIZE;
        if(i==hashValue) {
            printf("The hash table is full.\n");
            return;
        }
    }
    ht[i] = item;
}

void hashSearch(Element item, Element ht[]) {
    int i, hashValue;
    hashValue = hashFunction(item.key);
    i = hashValue;
    while (!empty(ht[i])) {
        if(equal(ht[i], item)) {
            printf("Discovery successful: existing.\n");
            return;
        }
        i = (i+1) % TABLE_SIZE;
        if(i==hashValue) break;
    }

    printf("No value found in table.\n");
}

void printHashTable(Element ht[]) {
    int i;
    for (i=0; i<TABLE_SIZE; i++) printf("[%d]\t%s\n", i, ht[i].key);
}

int main() {
    Element temp;
    int op;

    while(1) {
        printf("Enter (0) to insert a number, (1) to delete, (2) to print, (3) to End the program = ");
        scanf("%d", &op);

        if (op == 2) break;

        printf("Enter key: ");
        scanf("%s", temp.key);
        if (op==0) addHashTable(temp, hashTable);
        else if (op==1) hashSearch(temp, hashTable);
        printHashTable(hashTable);
    }

    return 0;
}
