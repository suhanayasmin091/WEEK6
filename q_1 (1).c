// Program to implement a stack using an array
#include <stdio.h>
#define MAX 10

int top = -1;
int st[MAX];

void push(int x) {
    if (top < MAX - 1) st[++top] = x;
}

int pop(void) {
    if (top == -1) return -1; 
    return st[top--];
}

int peek(void) {
    if (top == -1) return -1;
    return st[top];
}

void print_stack(void) {
    for (int i = top; i >= 0; --i) printf("%d ", st[i]);
    printf("\n");
}

int main(void) {
    int vals[] = {10, 20, 30, 40, 50}; 
    for (int i = 0; i < 5; ++i) push(vals[i]);
    printf("Stack after pushes: ");
    print_stack();
    printf("Popped: %d\n", pop());
    printf("Top now: %d\n", peek());
    printf("Final stack: ");
    print_stack();
    return 0;
}
