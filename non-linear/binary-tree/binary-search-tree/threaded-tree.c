#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *rptr; // lbit/rbit => 0 for node, 1 for thread
  struct Node *lptr;
  int lbit;
  int rbit;
} node;

node *dummy;

node *inorder_succ_for_new_node(
    node *p) { // find the inorder succesor for the leaf node being inserted
  node *store = NULL;
  node *t = dummy->lptr; // this node is used to traverse the tree
  if (!t) {
    printf("No tree yet :(\n");
    return store;
  }
  while (t->key != p->key && /* until key is found*/
         !(t->lbit && t->rbit) /* reached the end of tree */) {
    if (t->key > p->key) { // required key is smaller than node
      store = t;   // store this pointer as currently this is the last pointer
                   // from which we went left
      t = t->lptr; // go to left
    } else {
      t = t->rptr;
    }
  }
  return store;
}

node *inorder_pred_for_new_node(
    node *p) { // find the inorder predecessor for the node being inserted
  node *store = NULL;
  node *t = dummy->lptr; // this node is used to traverse the tree
  if (!t) {
    printf("No tree yet :(\n");
    return store;
  }
  while (t->key != p->key /* until we find the key */ &&
         !(t->lbit && t->rbit) /* until reached the end of tree */) {
    if (t->key > p->key) {
      t = t->lptr;
    } else {       // required key is larger than node
      store = t;   // store this pointer as currently this is the last pointer
                   // from which we went right
      t = t->rptr; // go to right
    }
  }
  return store;
}

void insert() {
  /* node creation */
  node *n = (node *)malloc(sizeof(node));
  int k;
  printf("Enter key: ");
  scanf("%d", &k);
  n->key = k;
  n->lbit = n->rbit = 1;
  /* root node creation */
  if (!dummy->lptr) {
    dummy->lptr = n;
    n->lbit = n->rbit = 1;
    n->lptr = n->rptr = dummy;
    return;
  }

  node *r1 = dummy->lptr; // root
  node *r2 = r1;
  while (1) { // until we reach the end of tree
    r2 = r1;
    if (r1->key < k) {
      if (r1->rbit) {
        break;
      }
      r1 = r1->rptr;
    } else {
      if (r1->lbit) {
        break;
      }
      r1 = r1->lptr;
    }
  }
  if (r2->key < k) {
    r2->rptr = n;
    r2->rbit = 0; // actual node is inserted
  } else {
    r2->lptr = n;
    r2->lbit = 0;
  }
  node *succ = inorder_succ_for_new_node(n);
  node *pred = inorder_pred_for_new_node(n);

  if (succ) {
    n->rptr = succ;
  } else {
    n->rptr = dummy;
  }
  if (pred) {
    n->lptr = pred;
  } else {
    n->lptr = dummy;
  }
}

node *inorder_succ_for_existing_node(node *n) { // for inorder traversal
  /* nodes already have their appropriate rbit and lbit set */
  if (n->rbit) { // if thread is present
    return n->rptr;
  }
  node *temp = n->rptr;
  while (!temp->lbit) { // else go to the left most node of right subtree
    temp = temp->lptr;
  }
  return temp;
}

void inorder_traversal() {
  node *temp = dummy->lptr;
  if (!temp) {
    printf("No tree yet :( \n");
    return;
  }
  while (!temp->lbit) {
    temp = temp->lptr;
  }
  printf("%d\t", temp->key);
  temp = inorder_succ_for_existing_node(temp);
  while (temp != dummy) {
    printf("%d\t", temp->key);
    temp = inorder_succ_for_existing_node(temp);
  }
  printf("\n");
}

int main() {
  /* create dummy node */

  dummy = (node *)malloc(sizeof(node));

  dummy->key = 9999;  // not a viable value for general inputs
  dummy->lbit = 0;    // lptr of dummy pointer is the root "node" thus lbit is 0
  dummy->rbit = 1;    // rptr of dummy pointer points to itself, i.e, kind of a
                      // thread, thus rbit is 0
  dummy->lptr = NULL; // initially there is no root node
  dummy->rptr = dummy; // rptr of dummy always points to itself;

  /* end of creation of dummy node */

  while (1) {
    printf("------\n1. Enter node\n2. Inorder\n3. Exit\n------\n");
    int input;
    scanf("%d", &input);
    switch (input) {
    case 1: {
      insert();
      break;
    }
    case 2: {
      inorder_traversal();
      break;
    }
    case 3: {
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
