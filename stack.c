#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ArrayStack {
    int top;
    int capacity;
    int *Array;
};
struct ArrayStack *stack = NULL;

void create_stack() {
    stack = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    int cap = 0;
    printf("Enter the capacity of the stack : ");
    scanf("%d", &cap);
    stack->capacity = cap;
    stack->top = -1;
    stack->Array = malloc(cap * sizeof(int));
}

bool isEmpty(struct ArrayStack *stack) {

    if(stack->top == -1) {
        return 1;
    }
    return 0;
}

bool isFull(struct ArrayStack *stack) {

    if(stack->top == stack->capacity-1) {
        return 1;
    }
    return 0;
}

void push(struct ArrayStack *stack, int data) {
    if(!isFull(stack)) {
        stack->top++;
        stack->Array[stack->top] = data;
    }
    else {
        printf("The stack is full\n");
    }
}

int pop(struct ArrayStack *stack) {
    if(isEmpty(stack)) {
        return -1;
    }
    else {
        int res = stack->Array[stack->top];
        stack->top--;
        return res;
    }
}

int main() {
    int x=0;
    int data=0;
    printf("MENU\n");
    printf("1. To create stack\n");
    printf("2. To push into stack\n");
    printf("3. To pop from the stack\n");
    printf("4. Check if stack empty\n");
    printf("5. Check if stack full\n");
    printf("6. Ending the program\n");
    do {
        printf("Enter your choice : ");
        scanf("%d", &x);
        switch(x) {
            case 1:
                    create_stack();
                    break;
            case 2:
                    printf("Value to be inserted : ");
                    scanf("%d", &data);
                    push(stack,data);
                    break;
            case 3:
                    data = pop(stack);
                    if(data == -1) {
                        printf("Nothing there in the stack\n");
                    }
                    else {
                        printf("Value at top : %d\n", data);
                    }
                    break;
            case 4:
                    if(isEmpty(stack)) {
                        printf("Stack is empty\n");
                    }
                    else {
                        printf("Stack not empty\n");
                    }
                    break;
            case 5:
                    if(isFull(stack)) {
                        printf("Stack is full\n");
                    }
                    else {
                        printf("Stack not full\n");
                    }
                    break;
            case 6:
                    printf("Ending the program\n");
                    break;
            default:
                    printf("Invalid choice Try Again");
                    break;
        }
    } while(x!=6);
}