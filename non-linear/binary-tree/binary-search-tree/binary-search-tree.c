#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int key;
  struct tree *left, *right;
} node;

node *root = NULL;

void create(int k) {
  node *x = (node *)malloc(sizeof(node)), *r1 = root, *r2;
  int ch;
  x->key = k;
  x->left = x->right = NULL;

  if (!root) {
    root = x;
    return;
  }
  while (r1) {
    r2 = r1;
    if (k <= r1->key)
      r1 = r1->left;
    else
      r1 = r1->right;
  }
  if (k <= r2->key)
    r2->left = x;
  else
    r2->right = x;
}

void inorder(node *r) {
  if (r) {
    inorder(r->left);
    printf("%d\t", r->key);
    inorder(r->right);
  }
}

void preorder(node *r) {
  if (r) {
    printf("%d\t", r->key);
    inorder(r->left);
    inorder(r->right);
  }
}

void postorder(node *r) {
  if (r) {
    inorder(r->left);
    inorder(r->right);
    printf("%d\t", r->key);
  }
}

int getNumberOfLeafNodes(node *r) {
  if (!r) {
    return 0;
  }
  if (r->left == NULL && r->right == NULL) { // checks for lead nodes
    return 1;                                // returns 1
  }
  return getNumberOfLeafNodes(r->left) + getNumberOfLeafNodes(r->right);
}

int getNumberOfNodes(node *r) {
  if (!r) {
    return 0; // returns 1
  }
  return getNumberOfNodes(r->left) + getNumberOfNodes(r->right) + 1;
}

int getNumberOfNonLeafNodes(node *r) {
  return getNumberOfNodes(r) - getNumberOfLeafNodes(r);
}

int main() {
  while (1 > 0) {
    int i;
    printf("\n1. Insert\n2. Inorder \n3. Preorder\n4. Postorder\n5. Get Number "
           "of Leaf Nodes\n6. Get Number of Nodes\n7. Get Number of Non Leaf "
           "Nodes\n8. Exit\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      printf("Enter key: ");
      scanf("%d", &i);
      create(i);
      break;
    }
    case 2: {
      printf("\n");
      inorder(root);
      break;
    }
    case 3: {
      printf("\n");
      preorder(root);
      break;
    }
    case 4: {
      printf("\n");
      postorder(root);
      break;
    }
    case 5: {
      printf("Number of leaf nodes: %d\n", getNumberOfLeafNodes(root));
      break;
    }
    case 6: {
      printf("Number of nodes: %d\n", getNumberOfNodes(root));
      break;
    }
    case 7: {
      printf("Number of non-leaf nodes: %d\n", getNumberOfNonLeafNodes(root));
      break;
    }
    case 8:
      exit(1);
    default:
      printf("Choose again\n");
    }
  }
}
