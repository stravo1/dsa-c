#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int key;
  struct list* next;
} node;

node* head = NULL;

void insert_end(int k) {

  node* new = (node*)malloc(sizeof(node)); // creating a new node
  // and passing the pointer to "new"
  new->key = k;     // assigning the value of key of the new node
  new->next = NULL; // assigning the value of the next pointer of new node

  if (!head) { // initialization
    head = new;
  }
  else {          // linked list initialized
    node* n = head; // n points to the 1st node

    while (n->next != NULL) { // until n->next is null, i.e., we reach the end
      n = n->next;            // make n point to the next node
    }
    n->next = new; // make the last node point to the new node
  }
}

void insert_first(int k) {
  if (!head) {
    insert_end(k);
    return;
  }
  node* new = (node*)malloc(sizeof(node)); // create new node
  new->key = k;
  new->next = head; // make the new point to old head => 1st node
  head = new;       // update head
}

void insert_pos(int k, int pos) {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return;
  }
  if (pos < 1) {
    printf("Position has to be 1 and more\n");
    return;
  }
  if (pos == 1) {
    insert_first(k);
    return;
  }
  node* n = head;                     // we are already at head
  for (int i = 0; i < pos - 2; i++) { // we need to iterate, at max, pos - 2
    // times to reach the node before pos
    n = n->next;
    if (!n) {
      printf("Position doesn't exist!\n");
      return;
    }
  }

  node* new = (node*)malloc(sizeof(node)); // create new node
  new->key = k;                             // put the key
  new->next = n->next;

  n->next = new; // insertion complete
}

int delete_last() {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return -1;
  }
  if (!head->next) { // there is no 2nd last element, it's just the head
    int val = head->key;
    free(head);
    head = NULL;
    return val;
  }
  node* n = head;
  while (n->next->next) { // go to the 2nd last element
    n = n->next;
  }
  int val = n->next->key;
  free(n->next); // deallocate memory
  n->next = NULL;
  return val;
}

int delete_first() {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return -1;
  }

  node* n = head;
  head = head->next; // make head point to the next node
  n->next = NULL; // make sure that the linked list can't be accessed in any way

  int val = n->key;
  free(n);
  return val;
}

int delete_pos(int pos) {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return -1;
  }
  if (pos < 1) {
    printf("Position has to be 1 and more.\n");
    return -1;
  }

  if (pos == 1) {
    return delete_first();
  }
  node* n = head;
  for (int i = 0; i < pos - 2; i++) { // iterate pos - 2 times
    n = n->next;                      // reach the node before pos
    if (!n) {
      printf("Position doesn't exist!\n");
      return -1;
    }
  }
  node* del = n->next; // node to be deleted
  n->next = del->next; // skip a node
  del->next = NULL;    // prevent any access

  int val = del->key;

  free(del);
  return val;
}

void display() {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return;
  }

  node* n = head;
  while (n) {
    printf("%d\t", n->key);
    n = n->next;
  }
  printf("\n");
}

void reverse() {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return;
  }
  if (!head->next) { // single node case
    printf("Linked list has only one node. No need of reversing!\n");
    return;
  }

  node* x, * y;
  x = head;

  y = x->next;
  x->next = NULL;

  if (!y->next) { // two nodes case
    y->next = x;
    head = y;
    return;
  }
  /* rest cases */
  head = y->next;
  y->next = x;

  while (head->next) {
    x = y;
    y = head;
    head = head->next;
    y->next = x;
  }
  head->next = y;
}

void middle() {


  if (head->next == NULL) {
    printf("middle element: %d\n", head->key);
  }
  else if (!head->next->next) {
    printf("middle element: %d and %d\n", head->key, head->next->key);
  }
  else {
    node* i = head->next;
    node* j = i->next;
    while (1) {
      if (j->next == NULL) {
        printf("middle element: %d\n", i->key);
        break;
      }
      else if (j->next->next == NULL) {
        printf("middle elements are: %d and %d\n", i->key, i->next->key);
        break;
      }

      else {
        i = i->next;
        j = j->next->next;
      }
    }
  }


}
int main() {
  while (1 > 0) {
    int i;
    printf("1. Insert \n2. Display \n3. Delete\n4. Reverse\n5. Find middle element\n6. Exit\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      printf("1. Front\n2. Middle\n3. End\n");
      scanf("%d", &i);
      switch (i) {
      case 1: {
        printf("Enter key: ");
        scanf("%d", &i);
        insert_first(i);
        break;
      }
      case 2: {
        int k, pos;
        printf("Enter key: ");
        scanf("%d", &k);
        printf("Enter position: ");
        scanf("%d", &pos);
        insert_pos(k, pos);
        break;
      }
      case 3: {
        printf("Enter key: ");
        scanf("%d", &i);
        insert_end(i);
        break;
      }
      default:
        printf("Choose again\n");
      }
      break;
    }
    case 2: {
      display();
      break;
    }
    case 3: {
      printf("1. Front\n2. Middle\n3. End\n");
      scanf("%d", &i);
      switch (i) {
      case 1: {
        delete_first();
        break;
      }
      case 2: {
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        delete_pos(pos);
        break;
      }
      case 3: {
        delete_last();
        break;
      }
      default:
        printf("Choose again\n");
      }
      break;
    }
    case 4:
      reverse();
      break;
    case 5:
      middle();
      break;
    case 6:
      exit(1);
    default:
      printf("Choose again\n");
    }
  }
}
