// Program to push and pop elements and display the stack after each operation
#include <stdio.h>
#define MAX 5

int st[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1) st[++top] = x;
}

int pop(void) {
    if (top == -1) return -1;
    return st[top--];
}

void print_stack(void) {
    if (top == -1) { printf("[empty]\n"); return; }
    for (int i = top; i >= 0; --i) {
        printf("%d", st[i]);
        if (i) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int vals[] = {15, 20, 25}; 
    int n = sizeof vals / sizeof *vals;

    for (int i = 0; i < n; ++i) {
        push(vals[i]);
        printf("push %d -> ", vals[i]);
        print_stack();
    }

    for (int i = 0; i < n; ++i) {
        int v = pop();
        printf("pop -> %d; ", v);
        print_stack();
    }

    return 0;
}
