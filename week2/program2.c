#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_SIZE 50

char stack[STACK_SIZE];
int top = -1;

// Function to push an operator onto the stack
void push(char c) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

// Function to pop an operator from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to get the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {  // If operand, add to postfix
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {  // Push '(' onto stack
            push(infix[i]);
        } else if (infix[i] == ')') {  // Pop until '(' is found
            while (top != -1 && (c = pop()) != '(') {
                postfix[j++] = c;
            }
        } else {  // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix string
}

void main() {
    char infix[50], postfix[50];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
}
