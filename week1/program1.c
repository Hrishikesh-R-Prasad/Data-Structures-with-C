#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack is full. Cannot push %d.\n", data);
    } else {
        stack[++top] = data;
        printf("%d pushed to stack.\n", data);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void main() {
    int choice, data;
    while (1) {
        printf("Stack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }
}
