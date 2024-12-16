#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertBeg(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    if(head == NULL) {
        head = tail = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertPos(int x) {
    struct node *newnode, *temp;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(pos == 1) {
        insertBeg(x);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        temp = head;
        for(int i = 1; i < pos-1 ; i++) {
            temp = temp->next;
            if(temp == NULL) {
                printf("There are less than %d nodes", pos);
                return;
            }
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        if(newnode->next != NULL)
            newnode->next->prev = newnode;
        else
            tail = newnode;
    }
}

void insertEnd(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL) {
        head = tail = newnode;
        newnode->prev = NULL;
    } else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void display() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int choice, x, pos;
    while(1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Insert at end\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &x);
                insertBeg(x);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &x);
                insertPos(x);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
