#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node {
    int data;
    struct Node* next;
} node;

static node* head = NULL;
static int nodeCount = 0;

int insertBack(int element) {
    node* current = (node*)malloc(sizeof(node));
    if (current) {
        current->data = element;
        current->next = NULL;
        if (head == NULL) head = current;
        else {
            node* previous = head;
            while (previous->next != NULL) previous = previous->next;
            previous->next = current;
        }
        nodeCount++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int deleteFront() {
    if (head != NULL) {
        node* current = head;
        head = head->next;
        free(current);
        nodeCount--;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void printList(void) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int getNodesCount() {
    return nodeCount;
}

void freeList(void) {
    while (nodeCount) deleteFront();
    head = NULL;
}
