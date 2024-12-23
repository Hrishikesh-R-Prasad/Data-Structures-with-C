#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = value;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}
void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
            exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}




