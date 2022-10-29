#include <stdio.h>
#include <stdlib.h>

typedef struct NODE node;
struct NODE {
  int key;
  node *next;
};

node *head = NULL;

void insert(int k, int pos) { // insert AT pos

  node *new = (node *)malloc(sizeof(node)); // create new node
  new->key = k;                             // fill the key part of the new node

  node *n = head;

  if (n == NULL && pos == 0) { // first element / initialization
    new->next = NULL;
    head = new;
    return;
  } else if (n == NULL &&
             pos != 0) { // if not initialized but illegal access is made
    free(new);
    printf("Linked list has not yet been initialized\n");
    return;
  }

  for (int i = 0; i < pos - 1; i++) { // reach pos by iterating pos - 2 times
    if (n->next == NULL) { // if trying to insert in an illegal position i.e.,
                           // pos is larger than the length of the list
      printf("The list is not that long :'(\n");
      free(new);
      return;
    }
    n = n->next;
  }

  /* MAIN ACTIONS */
  if (n->next == NULL && pos != 0) { // insert at the end but not when it's just
                                     // the head, i.e., only one node
    n->next = new;
    new->next = NULL;

  } else if (pos == 0) { // enter at beginning
    new->next = n;
    head = new;
  } else { // insert at the middle
    new->next = n->next;
    n->next = new;
  }
}

int delete (int pos) {
  if (head == NULL) {
    printf("Linked list has not yet been initialized\n");
    return -1;
  }
  node *n = head;
  if (pos == 0) { // for first element
    int val = n->key;
    head = n->next;
    n->next = NULL;
    free(n);
    return val;
  } else {
    for (int i = 0; i < pos - 1; i++) { // reach the required pos
      if (n->next == NULL) {            // exit if NULL encountered
        printf("Oops! Element doesn't exist!\n");
        return -1;
      }
      n = n->next;
    }
    if (n->next == NULL) { // if the pos - 1 is the last element
      printf("Oops! Element doesn't exist!\n");
      return -1;
    } else { // required pointer manipulations
      node *del = n->next;
      n->next = del->next;
      del->next = NULL;
      int val = del->key;
      free(del);
      return val;
    }
  }
}
void display() {
  node *n = head;
  if (n == NULL) {
    printf("Linked list has not yet been initialized\n");
    return;
  }
  while (n) {
    printf("%d \t", n->key);
    n = n->next;
  }
  printf("\n");
}

int main() {
  while (1 > 0) {
    int i;
    printf("1. Insert \n2. Display \n3. Delete\n4. Exit\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      int k, pos;
      printf("Enter key: ");
      scanf("%d", &k);
      printf("Enter position: ");
      scanf("%d", &pos);
      insert(k, pos);
      break;
    }
    case 2: {
      display();
      break;
    }
    case 3: {
      int p;
      printf("Enter position: ");
      scanf("%d", &p);
      delete (p);
      break;
    }
    case 4:
      exit(1);
    default:
      printf("Choose again\n");
    }
  }
}
