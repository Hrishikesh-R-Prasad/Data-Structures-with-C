#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void printList() {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct node *prev, *curr, *nextn;
    prev = NULL;
    curr = nextn = head;
    while(nextn != NULL) {
        nextn = nextn->next;
        curr->next = prev;
        prev = curr;
        curr = nextn;
    }
    head = prev;
}

void sort() {
    struct node *i, *j;
    int temp;
    for(i = head; i->next != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void concat(struct node *head1, struct node *head2) {
    struct node *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp2;
    printf("\n the concatenated list is \n");
    temp1 = head1;
    while(temp1 != NULL) {
        printf("%d", temp1->data);
        temp1 = temp1->next;
    }
}

void main() {
    int data;
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insert(data);
    }
    printf("Original List: ");
    printList();
    reverse();
    printf("Reversed List: ");
    printList();
    sort();
    printf("Sorted List: ");
    printList();
    struct node* head2 = NULL;
    printf("Enter the number of elements for list 2: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter element %d for list 2: ", i+1);
        scanf("%d", &data);
        insert(data);
    }
    printf("List 2: ");
    printList();
    concat(head, head2);
}
