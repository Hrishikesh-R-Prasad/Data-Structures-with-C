#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (top >= 0 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        } else {
            postfix[j++] = infix[i];
        }
    }

    while (top >= 0) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix arithmetic expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; 

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

}