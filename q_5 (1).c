/* Write a program to convert an infix expression into:
a)Postfix form (a+b → ab+)
b)Prefix form (a+b → +ab) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void reverseStr(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
        i++; j--;
    }
}

char *infixToPostfix(const char *in) {
    int n = strlen(in);
    char *stack = malloc(n + 1);
    int top = -1;
    char *out = malloc(n + 2);
    int k = 0;

    for (int i = 0; i < n; ++i) {
        char c = in[i];
        if (c == ' ' || c == '\t') continue;
        if (isalnum((unsigned char)c)) {
            out[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                out[k++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') top--; 
        } else if (isOperator(c)) {
            while (top >= 0 && isOperator(stack[top]) &&
                  ((precedence(stack[top]) > precedence(c)) ||
                   (precedence(stack[top]) == precedence(c) && c != '^'))) {
                out[k++] = stack[top--];
            }
            stack[++top] = c;
        } else {
            out[k++] = c;
        }
    }
    while (top >= 0) out[k++] = stack[top--];
    out[k] = '\0';
    free(stack);
    return out;
}

char *infixToPrefix(const char *infix) {
    int n = strlen(infix);
    char *rev = malloc(n + 1);
    strcpy(rev, infix);
    reverseStr(rev);

    for (int i = 0; i < n; ++i) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    char *post = infixToPostfix(rev);
    reverseStr(post);
    free(rev);
    return post; 
}

int main(void) {
    char expr[1024];
    printf("Enter infix expression: ");
    if (!fgets(expr, sizeof(expr), stdin)) return 0;
    size_t L = strlen(expr);
    if (L && expr[L-1] == '\n') expr[L-1] = '\0';

    char *post = infixToPostfix(expr);
    char *pre = infixToPrefix(expr);

    printf("Postfix: %s\n", post);
    printf("Prefix: %s\n", pre);

    free(post);
    free(pre);
    return 0;
}