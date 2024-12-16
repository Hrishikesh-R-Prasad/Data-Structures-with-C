#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertBeg() {
    int x;
    printf("Enter the value to be inserted : ");
    scanf("%d", &x);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = x;
    newnode->prev = NULL;
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertPos() {
    int x;
    printf("Enter the value to be inserted : ");
    scanf("%d", &x);
    struct node *newnode, *temp;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertBeg();
        return;
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;

        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("There are less than %d nodes\n", pos);
                free(newnode); // Avoid memory leak
                return;
            }
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}

void insertEnd() {
    int x;
    printf("Enter the value to be inserted : ");
    scanf("%d", &x);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->prev = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Insert at end\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertBeg();
                break;
            case 2:
                insertPos();
                break;
            case 3:
                insertEnd();
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
