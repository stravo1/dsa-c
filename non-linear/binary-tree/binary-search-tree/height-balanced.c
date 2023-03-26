#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  // int height;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;

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
  // n->height = 0;
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
      // r1->height-=1;
      r1 = r1->right;
    } else {
      // r1->height+=1;
      r1 = r1->left;
    }
  }
  if (r2->key < k) {
    r2->right = n;
  } else {
    r2->left = n;
  }
}

int height(NODE *r) {
  if (!r)
    return 0;
  int hl = height(r->left);
  int hr = height(r->right);
  // printf("%d %d\n", hl, hr);
  return 1 + (hl > hr ? hl : hr);
}

void postorder_rec(NODE *r) {
  if (!r) {
    return;
  }
  postorder_rec(r->left);
  postorder_rec(r->right);
  printf("%d\t", r->key);
}

void inorder_rec(NODE *r) {
  if (!r) {
    return;
  }
  inorder_rec(r->left);
  printf("%d\t", r->key);
  inorder_rec(r->right);
}

NODE *find_parent(int k) {
  NODE *r1 = root;
  NODE *r2 = r1;

  while (r1) {
    if (r1->key == k) {
      return r2;
    }
    r2 = r1;
    if (r1->key < k) {
      r1 = r1->right;
    } else {
      r1 = r1->left;
    }
  }
  printf("Not found!\n");
  return NULL;
}

void rotate_rr(NODE *r) {
  // r->height = r->right->height = 0;
  if (r == root) {
    root = r->right;
    r->right = root->left;
    root->left = r;
  } else {
    NODE *parent = find_parent(r->key);
    NODE *right_child = r->right;
    int flag;

    if (parent->left == r) {
      flag = 1;
    } else {
      flag = 0;
    }

    flag ? (parent->left = right_child) : (parent->right = right_child);
    r->right = right_child->left;
    right_child->left = r;
  }
}

void rotate_ll(NODE *r) {
  // r->height = r->left->height = 0;
  if (r == root) {
    root = r->left;
    r->left = root->right;
    root->right = r;
  } else {
    NODE *parent = find_parent(r->key);
    NODE *left_child = r->left;
    int flag;

    if (parent->left == r) {
      flag = 1;
    } else {
      flag = 0;
    }

    flag ? (parent->left = left_child) : (parent->right = left_child);
    r->left = left_child->right;
    left_child->right = r;
  }
}

void postorder_bal(NODE *r) {
  if (!r) {
    return;
  }
  postorder_bal(r->left);
  postorder_bal(r->right);
  if ((height(r->left) - height(r->right)) < -1) {
    // printf("%d \n", (height(r->left)  - height(r->right)));
    if ((height(r->right->left) - height(r->right->right)) > 0) {
      rotate_ll(r->right);
      rotate_rr(r);
    } else
      rotate_rr(r);
  } else if ((height(r->left) - height(r->right)) > 1) {
    if ((height(r->left->left) - height(r->left->right)) < 0) {
      rotate_rr(r->left);
      rotate_ll(r);
    } else
      rotate_ll(r);
  }
}
int main() {
  while (1) {
    printf("------\n1. Enter node\n2. Post Order "
           "\n3. Inorder\n4. Exit\n------\n");
    int input;
    scanf("%d", &input);
    switch (input) {
    case 1: {
      insert();
      postorder_bal(root);
      break;
    }
    case 2: {
      postorder_rec(root);
      printf("\n");
      break;
    }
    case 3: {
      inorder_rec(root);
      printf("\n");
      break;
    }
    case 4: {
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
