
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void createList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertLeft(int data, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            if (temp == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            struct Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL) {
                temp->next->prev = temp;
            }
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int data;
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        createList(data);
    }
    printf("Original List: ");
    displayList();
    int value, newData;
    printf("Enter the value to insert before: ");
    scanf("%d", &value);
    printf("Enter the new data: ");
    scanf("%d", &newData);
    insertLeft(newData, value);
    printf("List after insertion: ");
    displayList();
    int deleteValue;
    printf("Enter the value to delete: ");
    scanf("%d", &deleteValue);
    deleteNode(deleteValue);
    printf("List after deletion: ");
    displayList();
}
