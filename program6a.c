#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* sortList(struct node* head) {
    struct node* current = head;
    int temp;
    while (current != NULL) {
        struct node* index = current;
        while (index->next != NULL) {
            if (current->data > index->next->data) {
                temp = current->data;
                current->data = index->next->data;
                index->next->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return head;
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* concatenateLists(struct node* head1, struct node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    struct node* current = head1;
    while (current->next != NULL)
        current = current->next;
    current->next = head2;
    return head1;
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void main() {
    int n1, n2, n3, n4, n5, n6;
    printf("Enter the data for List 1 (3 nodes): ");
    scanf("%d %d %d", &n1, &n2, &n3);

    printf("Enter the data for List 2 (3 nodes): ");
    scanf("%d %d %d", &n4, &n5, &n6);

    struct node* head1 = createNode(n1);
    head1->next = createNode(n2);
    head1->next->next = createNode(n3);

    struct node* head2 = createNode(n4);
    head2->next = createNode(n5);
    head2->next->next = createNode(n6);

    printf("List 1 before sorting: ");
    printList(head1);
    head1 = sortList(head1);
    printf("List 1 after sorting: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct node* concatenatedList = concatenateLists(head1, head2);
    printf("Concatenated List: ");
    printList(concatenatedList);

    struct node* reversedList = reverseList(concatenatedList);
    printf("Reversed Concatenated List: ");
    printList(reversedList);
}