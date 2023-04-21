#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

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

  int adjacencyMatrix[n][n];

  /* initialization of the matrix */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adjacencyMatrix[i][j] = 0;
    }
  }

  /* get all the edges */
  int t;
  printf("\nEnter number of edges: ");
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    /* get the names for the nodes which make up the edge */
    char node1, node2;

    printf("\nEnter 1st node for edge %d: ", i + 1);
    scanf(" %c", &node1);

    printf("Enter 2nd node for edge %d: ", i + 1);
    scanf(" %c", &node2);

    /* get the actual index of the nodes */
    int index1 = getIndexOf(node1, names, n);
    int index2 = getIndexOf(node2, names, n);
    adjacencyMatrix[index1][index2] = 1; // update the matrix
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
    int node = pop();             // pop
    for (int i = 0; i < n; i++) { // check for neighbours
      if (adjacencyMatrix[node][i] && !visited[i]) {
        push(i);
        visited[i] =
            1; // if unvisited neighbour found enqueue ut and mark it visited
      }
    }
    printf("%c\t", names[node]);
  }
}
