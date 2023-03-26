#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;
NODE *parent = NULL, *child;

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

NODE *inorder_succ(NODE *n) {
  NODE *temp = n->right;
  while (temp->left) {
    temp = temp->left;
  }
  return temp;
}

void dlt(int);

void case0(NODE *p, NODE *c) {
  if (!p) { // if root is to be deleted
    root = NULL;
    free(p);
    return;
  }
  if (p->left == c) {
    p->left = NULL;
  } else {
    p->right = NULL;
  }
  free(c);
}

void case1(NODE *p, NODE *c) {
  if (!p) { // if root is to be deleted
    c->left ? (root = c->left) : (root = c->right);
    free(c);
    return;
  }
  int flag = 0; // to check if child is in the left or right of parent (0 for
                // right, 1 for left)
  if (p->left == c) {
    flag = 1;
  }
  if (c->left) {
    flag ? (p->left = c->left) : (p->right = c->left);
    c->left = NULL;
    free(c);
  } else {
    flag ? (p->left = c->right) : (p->right = c->right);
    c->right = NULL;
    free(c);
  }
}

void case2(NODE *p) {
  NODE *inorder_succ_node = inorder_succ(p);
  int key = inorder_succ_node->key;
  dlt(inorder_succ_node->key);
  p->key = key;
}

void dlt(int k) {
  int no_of_children;
  findAddr(k);

  if (child->left && child->right) {
    no_of_children = 2;
  } else if (child->left || child->right) {
    no_of_children = 1;
  } else {
    no_of_children = 0;
  }
  switch (no_of_children) {
  case 0: {
    case0(parent, child);
    break;
  }
  case 1: {
    case1(parent, child);
    break;
  }
  case 2: {
    case2(child);
    break;
  }
  }
}

void postorder(NODE *r) {
  if (!r) {
    return;
  }
  postorder(r->left);
  postorder(r->right);
  printf("%d\t", r->key);
}

void inorder(NODE *r) {
  if (!r) {
    return;
  }
  inorder(r->left);
  printf("%d\t", r->key);
  inorder(r->right);
}

int main() {
  while (1) {
    printf("------\n1. Enter node\n2. Post Order\n3. Inorder\n4. Find a "
           "node\n5. Delete a node\n6. Exit\n------\n");
    int input;
    scanf("%d", &input);
    switch (input) {
    case 1: {
      insert();
      break;
    }
    case 2: {
      postorder(root);
      printf("\n");
      break;
    }
    case 3: {
      inorder(root);
      printf("\n");
      break;
    }
    case 4: {
      printf("Enter key: ");
      int i;
      scanf("%d", &i);
      findAddr(i);
      if (parent && child)
        printf("%d is the parent of %d\n", parent->key, child->key);
      else if (!parent && child) {
        printf("The root node has the key %d\n", i);
      } else
        printf("Key not found!\n");
      break;
    }
    case 5: {
      printf("Enter key: ");
      int i;
      scanf("%d", &i);
      dlt(i);
      break;
    }
    case 6: {
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
