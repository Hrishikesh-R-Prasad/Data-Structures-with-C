#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void createList() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteSpecified() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        int data;
        printf("Enter the element to delete: ");
        scanf("%d", &data);
        if (head->data == data) {
            deleteFirst();
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                if (temp->next->data == data) {
                    struct Node* nodeToDelete = temp->next;
                    temp->next = temp->next->next;
                    free(nodeToDelete);
                    return;
                }
                temp = temp->next;
            }
            printf("Element not found\n");
        }
    }
}


void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->next == NULL) {
                free(temp->next);
                temp->next = NULL;
                return;
            }
            temp = temp->next;
        }
    }
}
void main() {
    int choice;
    while (1) {
        printf("1. Create List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                deleteSpecified();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                displayList();
                break;
            case 6:
               printf("Exiting the program\n");
               exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}