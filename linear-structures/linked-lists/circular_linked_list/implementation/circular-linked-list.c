#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int key;
  struct list *next;
} node;

node *head = NULL;
node *tail = NULL;

void insert_end(int k) {

  node *new = (node *)malloc(sizeof(node)); // creating a new node
                                            // and passing the pointer to "new"
  new->key = k; // assigning the value of key of the new node

  if (!head) { // initialization
    head = tail = new;
    tail->next = head; // head is both tail and head at the same time
  } else {             // linked list initialized
    tail->next = new;  // make the last node point to the new node
    new->next = head;  // make the last node point to head
    tail = new;        // update tail
  }
}

void insert_first(int k) {
  if (!head) {
    insert_end(k);
    return;
  }
  node *new = (node *)malloc(sizeof(node)); // create new node
  new->key = k;
  new->next = head; // make the new point to old head => 1st node

  head = new;        // update head
  tail->next = head; // update tail to point to
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
  node *n = head;                     // we are already at head
  for (int i = 0; i < pos - 2; i++) { // we need to iterate, at max, pos - 2
                                      // times to reach the node before pos
    n = n->next;
    if (!n) {
      printf("Position doesn't exist!\n");
      return;
    }
  }

  node *new = (node *)malloc(sizeof(node)); // create new node
  new->key = k;                             // put the key
  new->next = n->next;

  n->next = new; // insertion complete
  if (n == tail)
    tail = new;
}

int delete_last() {
  if (!head) {
    printf("Linked list has not yet been initialized\n");
    return -1;
  }
  if (tail == head) { // there is no 2nd last element
    int val = head->key;
    free(head);
    head = tail = NULL;
    return val;
  }
  node *n = head;
  while (n->next->next != head) { // go to the 2nd last element
    n = n->next;
  }
  int val = n->next->key;
  n->next->next = NULL; // remove access
  free(n->next);        // deallocate memory
  n->next = head;       // make this the last node => has to point back to head
  return val;
}

int delete_first() {
  if (!head) { // empty linked list
    return -1;
  }
  if (tail == head) { // there is no 2nd last element
    int val = head->key;
    free(head);
    head = tail = NULL;
    return val;
  }
  node *del = head;  // node to be deleted
  head = head->next; // make head point to the next node
  del->next =
      NULL; // make sure that the linked list can't be accessed in any way

  tail->next = head; // make tail point to new head
  int val = del->key;
  free(del);
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
  node *n = head;
  for (int i = 0; i < pos - 2; i++) { // iterate pos - 2 times
    n = n->next;                      // reach the node before pos
    if (!n) {
      printf("Position doesn't exist!\n");
      return -1;
    }
  }
  node *del = n->next; // node to be deleted
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

  node *n = head;
  do {
    printf("%d\t", n->key);
    n = n->next;
  } while (n != head);
  printf("\n");
}
