#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int pop() {
    if (head == NULL) return -1;
    int data = head->data;
    struct node* temp = head;
    head = head->next;
    free(temp);
    return data;
}

void enqueue(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) head = new_node;
    else {
        struct node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_node;
    }
}

int dequeue() {
    if (head == NULL) return -1;
    int data = head->data;
    struct node* temp = head;
    head = head->next;
    free(temp);
    return data;
}
void main() {
    int data;
    printf("Enter the number of elements: ");
    scanf("%d", &data);
    for (int i = 0; i < data; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }
    printf("Popped elements: \n");
    for (int i = 0; i < data; i++) {
        printf("%d\n", pop());
    }
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &data);
    for (int i = 0; i < data; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Dequeued elements: \n");
    for (int i = 0; i < data; i++) {
        printf("%d\n", dequeue());
    }
}