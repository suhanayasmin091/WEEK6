// Program to evaluate a postfix expression
#include <stdio.h>
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
    char *e;
    int n1, n2, num;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    e = exp;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0');  
        } else {
            n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+': push(n2 + n1); break;
                case '-': push(n2 - n1); break;
                case '*': push(n2 * n1); break;
                case '/': push(n2 / n1); break;
            }
        }
        e++;
    }
    printf("Result = %d\n", pop());
    return 0;
}
