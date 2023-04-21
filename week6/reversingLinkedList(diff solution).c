#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list structure
typedef struct LinkedList {
    int count;
    Node* head;
} LinkedList;

// Stack node structure
typedef struct StackNode {
    Node* node;
    struct StackNode* next;
} StackNode;


void reverseList(LinkedList* list, StackNode** top);
void showNode(LinkedList* list);
void makeEmpty(LinkedList* list);
void push(StackNode** top, Node* node);
Node* pop(StackNode** top);
void addNode(LinkedList* list, int position, int data);

// Print the linked list
/*void showNode(LinkedList* list) {
    printf("Linked list: ");
    Node* curNode = list->head;
    while (curNode != NULL) {
        printf("%d ", curNode->data);
        curNode = curNode->next;
    }
    printf("\n");
}*/


void showNode(LinkedList* list) {
    printf("Current Node Count: %d\n", list->count);
    Node* curNode = list->head;
    while (curNode != NULL) {
        printf("[%d]\n", curNode->data);
        curNode = curNode->next;
    }
    printf("\n");
}

// Free all nodes in the linked list
void makeEmpty(LinkedList* list) {
    Node* curNode = list->head;
    while (curNode != NULL) {
        Node* nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    list->count = 0;
    list->head = NULL;
}

// Push a node onto the top of the stack
void push(StackNode** top, Node* node) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->node = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

// Pop the top node from the stack
Node* pop(StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    StackNode* curStackNode = *top;
    *top = curStackNode->next;
    Node* curNode = curStackNode->node;
    free(curStackNode);
    return curNode;
}

// Reverse the order of nodes in the linked list using the stack
void reverseList(LinkedList* list, StackNode** top) {
    Node* curNode = list->head;
    while (curNode != NULL) {
        push(top, curNode);
        curNode = curNode->next;
    }
    list->head = pop(top);
    curNode = list->head;
    while (curNode != NULL) {
        Node* tmpNode = pop(top);
        curNode->next = tmpNode;
        curNode = curNode->next;
    }
}

// Add a new node with given data at the given position in the linked list
void addNode(LinkedList* list, int position, int data) {
	
	int i;
    // Create a new node with given data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        // Insert at the beginning of the list
        newNode->next = list->head;
        list->head = newNode;
    } else if (position < list->count) {
        // Insert at the given position
        Node* prevNode = list->head;
        for ( i = 0; i < position - 1; i++) {
            prevNode = prevNode->next;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    } else {
        // Insert at the end of the list
        Node* curNode = list->head;
        while (curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }

    list->count++;
}

       



int main() {
    // Create a linked list with some nodes
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->count = 0;
    list->head = NULL;
    
    addNode(list, 0, 10);
    addNode(list, 5, 100);
    addNode(list, 1, 20);
    addNode(list, 2, 30);
    addNode(list, 1, 50);
    addNode(list, 1, 70);
    addNode(list, 1, 40);
    
    // Print the original linked list
    printf("------------------------------------------\n");
    showNode(list);

    // Reverse the order of nodes in the linked list using the stack
    StackNode* top = NULL;
    reverseList(list, &top);

    // Print the reversed linked list
    printf("-------------------------------\n");
    printf("Reversed Linked List!\n");
    showNode(list);

    // Free memory used by the linked list
    printf("--------------------------\n");
    printf("Current Node Count: 0\n");
    makeEmpty(list);
    free(list);

    return 0;
}