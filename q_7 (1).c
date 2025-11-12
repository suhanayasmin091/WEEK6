// Program to evaluate a prefix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[50];
    int i, n1, n2;
    
    printf("Enter prefix expression: ");
    scanf("%s", exp);

    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            n1 = pop();
            n2 = pop();
            switch (exp[i]) {
                case '+': push(n1 + n2); break;
                case '-': push(n1 - n2); break;
                case '*': push(n1 * n2); break;
                case '/': push(n1 / n2); break;
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}