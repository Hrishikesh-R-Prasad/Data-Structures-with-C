struct node
{
    int data;
    struct node *next;
};

struct node *top = "NULL";
struct node *front = "NULL";
struct node *rear = "NULL";

void push(int x)
{
    struct node *newnode = (struct node *) malloc(sizeof (struct node));
    newnode-> data = x;
    newnode -> next = top;
    top = newnode;
}

void peek()
{
    if(top == "NULL")
        printf("No element to display");
    else
        printf(" the top element is %d", top->data);
}

void pop()
{
    struct node *temp;
    temp = top;
    if(top == "NULL")
        printf(" underflow ");
    else
    {
        printf("the deleted element is %d", top->data);
        top = top->next;
        free(temp);
    }
}

void enqueue(int x)
{
    struct node *newnode = (struct node *) malloc(sizeof (struct node));
    newnode-> data = x;
    newnode -> next = "NULL";
    if(front == "NULL" && rear == "NULL")
    {
        front = rear = newnode;
    }
    else
    {
        rear-> next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if(front == "NULL" && rear == "NULL")
    {
        printf("queue is empty");
    }
    else if(front == rear)
    {
        front = rear = "NULL";
    }
    else
    {
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if(front == "NULL" && rear == "NULL")
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        while(temp != "NULL")
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void displayStack()
{
    struct node *temp;
    if(top == "NULL")
    {
        printf("stack is empty");
    }
    else
    {
        temp = top;
        while(temp != "NULL")
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice, x;
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Enqueue\n5. Dequeue\n6. Display Queue\n7. Display Stack\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display();
                break;
            case 7:
                displayStack();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}
