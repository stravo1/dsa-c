#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;
NODE *parent = NULL, *child;

/* START OF STACC DECLARATION */

/* the members which will be inserted in stack */
typedef struct pointer {
  int flag;
  NODE *ptr;
} PTR;

int top = -1;    // top of the stack
PTR *stack[100]; // stack of pointers along with their flags

void push(PTR *k) {
  if (top == 100) {
    printf("Overflow!\n");
    return;
  }
  stack[++top] = k;
}

PTR *pop() {
  if (top == -1) {
    printf("Underflow\n");
    return NULL;
  }
  return stack[top--];
}

/* END OF STACC DECLARATION */

/* basic insertion function */
void insert() {
  /* node creation */
  NODE *n = (NODE *)malloc(sizeof(NODE));
  int k;
  printf("Enter key: ");
  scanf("%d", &k);
  n->key = k;
  n->left = NULL;
  n->right = NULL;

  /* basic insertion */
  if (!root) {
    root = n;
    return;
  }
  NODE *r1 = root;
  NODE *r2 = r1;
  while (r1) {
    r2 = r1;
    if (r1->key < k) {
      r1 = r1->right;
    } else {
      r1 = r1->left;
    }
  }
  if (r2->key < k) {
    r2->right = n;
  } else {
    r2->left = n;
  }
}

void findAddr(int k) {
  NODE *r = root;
  parent = NULL;
  child = root; // if root has the key then the while loop wont execute
  while (r->key != k) {
    if (!r->left && !r->right) {
      parent = child = NULL;
      return;
    }
    parent = r;
    if (k > r->key) {
      r = r->right;
    } else {
      r = r->left;
    }
  }
  child = r;
}

void process_post(NODE *root) {

  while (root) { // go to the left most node of the given root

    /* create a member which will be inserted in the stack */
    PTR *n = (PTR *)malloc(sizeof(PTR));
    n->ptr = root;
    n->flag = 0;
    push(n);

    if (root->right) { // if right of node exists push node with flag
      PTR *n = (PTR *)malloc(sizeof(PTR));
      n->ptr = root->right; // pushing the right node
      n->flag = 1; // setting flag that it needs to be processed further
      push(n);     // push the right node
    }
    root = root->left;
  }
}
void postorder() {
  NODE *ptr = root;
  if (!ptr) {
    printf("No tree yet :(\n");
    return;
  }
  process_post(ptr);             // process the root first
  while (top != -1) {            // until stack is empty
    PTR *popped = pop();         // pop element
    if (popped->flag) {          // if flag is set
      process_post(popped->ptr); // process that node
    } else {                     // else print the node
      printf("%d\t", popped->ptr->key);
    }
  }
}

void process_in(NODE *root) {

  while (root) { // similar to post but here right node is pushed first

    if (root->right) { // if right of node exists push node with flag
      PTR *n = (PTR *)malloc(sizeof(PTR));
      n->ptr = root->right; // pushing the right node
      n->flag = 1; // setting flag that it needs to be processed further
      push(n);     // push the right node
    }
    /* create a member which will be inserted in the stack */
    PTR *n = (PTR *)malloc(sizeof(PTR));
    n->ptr = root;
    n->flag = 0;
    push(n);
    root = root->left;
  }
}

void inorder() {
  NODE *ptr = root;
  if (!ptr) {
    printf("No tree yet :(\n");
    return;
  }
  process_in(ptr);             // process the root first
  while (top != -1) {          // until stack is empty
    PTR *popped = pop();       // pop element
    if (popped->flag) {        // if flag is set
      process_in(popped->ptr); // process that node
    } else {                   // else print the node
      printf("%d\t", popped->ptr->key);
    }
  }
}

void process_pre(NODE *root) {

  while (root) { // similar to post but herewe go to the rightmost node first

    /* create a member which will be inserted in the stack */
    PTR *n = (PTR *)malloc(sizeof(PTR));
    n->ptr = root;
    n->flag = 0;
    push(n);

    if (root->left) { // if right of node exists push node with flag
      PTR *n = (PTR *)malloc(sizeof(PTR));
      n->ptr = root->left; // pushing the right node
      n->flag = 1;         // setting flag that it needs to be processed further
      push(n);             // push the right node
    }
    root = root->right;
  }
}

void preorder() {
  NODE *ptr = root;
  if (!ptr) {
    printf("No tree yet :(\n");
    return;
  }
  process_pre(ptr);             // process the root first
  while (top != -1) {           // until stack is empty
    PTR *popped = pop();        // pop element
    if (popped->flag) {         // if flag is set
      process_pre(popped->ptr); // process that node
    } else {                    // else print the node
      printf("%d\t", popped->ptr->key);
    }
  }
}

int main() {
  while (1) {
    printf("------\n1. Enter node\n2. Post Order\n3. Inorder\n4. Pre Order"
           "\n5. Exit\n------\n");
    int input;
    scanf("%d", &input);
    switch (input) {
    case 1: {
      insert();
      break;
    }
    case 2: {
      postorder();
      printf("\n");
      break;
    }
    case 3: {
      inorder();
      printf("\n");
      break;
    }
    case 4: {
      preorder();
      printf("\n");
      break;
    }
    case 5: {
      exit(1);
      break;
    }
    default: {
      printf("Wrong choice!\n");
      break;
    }
    }
  }
}
