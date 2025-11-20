#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i = 0;
    int a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    while (postfix[i] != '\0') {

        // If operand → push to stack
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');   // convert char to int
        }

        // If operator → pop two, apply operator, push result
        else {
            b = pop();
            a = pop();

            switch (postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
            }

            push(result);
        }

        i++;
    }

    printf("Final result = %d\n", pop());

    return 0;
}
