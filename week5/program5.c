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
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void delete_specified() {
    struct node* ptr, *ptr1;
    int loc, i;

    printf("Enter the location of the node to delete: ");
    scanf("%d", &loc);

    ptr = head;

    if (loc == 1) {
        head = ptr->next;
        free(ptr);
    } else {
        for (i = 1; i < loc; i++) {
            ptr1 = ptr;
            ptr = ptr->next;

            if (ptr == NULL) {
                printf("\nThere are less than %d elements in the list..\n", loc);
                return;
            }
        }

        ptr1->next = ptr->next;
        free(ptr);
    }

    printf("\nDeleted %d node ", loc);
}

void end_delete() {
    struct node* ptr, *ptr1;

    if (head == NULL) {
        printf("\nlist is empty");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted ...");
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }

        ptr1->next = NULL;
        free(ptr);
        printf("\n Deleted Node from the last ...");
    }
}


void Pop() {
    struct node* ptr;

    if (head == NULL) {
        printf("\nList is empty");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\n Node deleted from the begining ...");
    }
}

void display() {
    struct node* ptr = head;

    if (head == NULL) {
        printf("\nList is empty");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void main() {
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete specified node\n3. Delete last node\n4. Delete first node\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                delete_specified();
                break;
            case 3:
                end_delete();
                break;
            case 4:
                Pop();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

}
