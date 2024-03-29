#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct list {
  int key;
  struct list *next;
} node;

/* STACK DECLARATION */
int stack[STACK_SIZE], top = -1;

void push(int k) {
  if (top == STACK_SIZE) {
    printf("ERR: STACK FULL!\n");
    return;
  }
  stack[++top] = k;
}

int pop() {
  if (top == -1) {
    printf("ERR: STACK EMPTY\n");
    return -1;
  }
  return stack[top--];
}

/* get index of an element from an array */
int getIndexOf(char needle, char haystack[], int len) {
  for (int i = 0; i < len; i++) {
    if (haystack[i] == needle) {
      return i;
    }
  }
  printf("ERR: NAME NOT FOUND\n");
  exit(0);
}

int main() {
  int n;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  /* get names for all nodes */
  char names[n];
  printf("\n|| NAMES SHOULD BE SINGLE CHARACTERS ||\n");
  for (int i = 0; i < n; i++) {
    printf("Enter name for node %d: ", i + 1);
    scanf(" %c", &names[i]);
  }

  node *list[n];
  for (int i = 0; i < n; i++) {
    list[i] = NULL; // initialization

    int nOn; // number-of-neighbours
    printf("\nEnter number of neighbours of %c: ", names[i]);
    scanf("%d", &nOn);

    for (int j = 0; j < nOn; j++) {
      char c;
      printf("Enter the name of the %d(th) neighbour: ", j + 1);
      scanf(" %c", &c);

      int k = getIndexOf(c, names, n);

      /* create new node */
      node *new = (node *)(malloc(sizeof(node)));
      new->key = k;
      new->next = NULL;

      node *temp = list[i];
      if (!temp) { // create the 1st link
        list[i] = new;
      } else { // add to the end of the list
        while (temp->next) {
          temp = temp->next;
        }
        temp->next = new;
      }
    }
  }

  /* keeps track of visited nodes */
  int visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  /* get starting node */
  char init;
  printf("\nEnter starting name of node: ");
  scanf(" %c", &init);
  int startingIndex = getIndexOf(init, names, n);

  /* push and mark the starting node as visited */
  push(startingIndex);
  visited[startingIndex] = 1;

  /* until stack is empty */
  while (top != -1) {
    int n = pop(); // pop
    node *temp = list[n];
    while (temp) { // check for neighbour
      int i = temp->key;
      if (!visited[i]) {
        push(i);
        visited[i] =
            1; // if unvisited neighbour found enqueue ut and mark it visited
      }
      temp = temp->next;
    }
    printf("%c\t", names[n]);
  }
}
