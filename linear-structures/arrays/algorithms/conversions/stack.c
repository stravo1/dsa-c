#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int x) {
  if (top == SIZE - 1) {
    printf("Stack full!\n");
    return;
  }
  stack[++top] = x;
}

int peek() {
  if (top == -1) {
    return -1;
  }
  return (stack[top]);
}

int pop() {
  if (top == -1) {
    printf("Stack empty!\n");
    return -1;
  }
  return stack[top--];
}

void display() {
  if (top == -1) {
    printf("Stack empty!\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("%d \t", stack[i]);
  }
}
