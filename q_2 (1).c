// Program to implement a stack using a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x) {
    Node *n = malloc(sizeof *n);
    if (!n) return;
    n->data = x;
    n->next = top;
    top = n;
}

int pop(void) {
    if (!top) return -1;
    Node *n = top;
    int v = n->data;
    top = n->next;
    free(n);
    return v;
}

int peek(void) {
    return top ? top->data : -1;
}

void print_stack(void) {
    for (Node *p = top; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main(void) {
    int vals[] = {1, 12, 44, 54, 99}; 
    for (int i = 0; i < 5; ++i) push(vals[i]);

    printf("Stack after pushes: ");
    print_stack();

    printf("Popped: %d\n", pop());
    printf("Top now: %d\n", peek());

    printf("Final stack: ");
    print_stack();
    return 0;
}
