    #include <stdio.h>
    #include <stdlib.h>

    #define MAX 3

    int queue[MAX];
    int front = -1;
    int rear = -1;

    void insert(int item) {
        if (rear == MAX - 1)
            printf("Queue overflow\n");
        else if (front == -1) {
            front = 0;
            rear = 0;
            queue[rear] = item;
        } else {
            rear++;
            queue[rear] = item;
        }
    }
    void delete() {
        if (front == -1)
            printf("Queue empty\n");
        else if (front == rear) {
            printf("Deleted item is %d\n", queue[front]);
            front = -1;
            rear = -1;
        } else {
            printf("Deleted item is %d\n", queue[front]);
            front++;
        }
    }

    void display() {
        if (front == -1)
            printf("Queue empty\n");
        else {
            printf("Queue elements are: ");
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
            printf("\n");
        }
    }

    void main() {
        int choice, item;
        while (1) {
            printf("1.Insert\n");
            printf("2.Delete\n");
            printf("3.Display\n");
            printf("4.Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter the item to be inserted: ");
                    scanf("%d", &item);
                    insert(item);
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





