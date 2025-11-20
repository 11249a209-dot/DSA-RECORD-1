#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char x) {
    stack[++top] = x;
}

// Pop from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Priority function
int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[100], postfix[100], x;
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {

        // If operand → add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(' → push
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')' → pop until '('
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        }

        // Operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
