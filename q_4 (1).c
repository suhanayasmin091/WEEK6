// Program to check stack overflow and underflow conditions
#include <stdio.h>
#define MAX 5

int st[MAX], top = -1;

void push(int x) {
    if (top >= MAX - 1) {
        printf("Overflow: cannot push %d\n", x);
        return;
    }
    st[++top] = x;
}

int pop(void) {
    if (top == -1) {
        printf("Underflow: cannot pop\n");
        return -1;
    }
    return st[top--];
}

void print_stack(void) {
    if (top == -1) { printf("[empty]\n"); return; }
    for (int i = top; i >= 0; --i) printf("%d ", st[i]);
    printf("\n");
}

int main(void) {
    int vals[] = {10, 20, 30, 40, 50}; 
    for (int i = 0; i < 5; ++i) push(vals[i]);
    push(60);
    printf("Stack now: ");
    print_stack();

    for (int i = 0; i < 6; ++i) {
        int v = pop();
        if (v != -1) printf("popped %d\n", v);
    }

    printf("Final stack: ");
    print_stack();
    return 0;
}
