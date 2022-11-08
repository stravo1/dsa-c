#include <stdio.h>
#define SIZE 20

int heap[SIZE], indx = -1;

void swap(int old, int new) {
  int temp = heap[old];
  heap[old] = heap[new];
  heap[new] = temp;
}

void insert(int k) {

  heap[++indx] = k;      // insert k at the end of the array/heap
  int childIndex = indx; // create a local copy of the index so as to not mess
                         // up the original index
  int parentIndex = (childIndex - 1) / 2;
  while (heap[childIndex] > heap[parentIndex]) {
    /* swap parent and child */
    swap(parentIndex, childIndex);

    /* make the curent parentIndex the new child and compare again */
    childIndex = parentIndex;
    parentIndex = (childIndex - 1) / 2;
  }
}

void deleteAndHeapify() {
  if (indx == -1) { // empty heap
    return;
  }

  int parent = 0;
  while (1) { // run until we reach the end of the heap or a leaf node (come out
              // using break)

    int leftChild = parent * 2 + 1;  // calc position of left child
    int rightChild = parent * 2 + 2; // calc position of right child

    if (leftChild <= indx) {                      // if left child exists
      if (rightChild <= indx) {                   // and right child exists
        if (heap[leftChild] > heap[rightChild]) { // compare them
          swap(parent, leftChild);                // swap the bigger one
          parent = leftChild;                     // update parent
        } else {
          swap(parent, rightChild); // swap the bigger one
          parent = rightChild;      // update parent
        }
      } else { // rightchild doesn't exist => we have reached the end of the
               // heap
        swap(parent, leftChild);
        break;
      }
    } else { // leftchild doesn't exist => we have reached the end LEVEL of the
             // heap (or a leaf node), not necessarily the end of the heap
      /*
      case 1: we have reached the end of the heap, here swapping makes no
      difference case 2: we have reached a leaf node, here we swap the end of
      the heap with the current position [as we have always chosen the larger
      number thus even if we are in a diff. parent compared to the end of the
      heap, the end of the heap will be smaller than the current position]
      */
      swap(parent, indx);
      break;
    }
  }
  indx--;
}

int main() {
  int size = -1;
  int disturbed = 0;
  while (1) {
    int inp;
    printf("\n1. Insert \n2. Delete and Heapify \n3. View \n4. Reset\n5. Exit "
           "\n\n");
    scanf("%d", &inp);
    switch (inp) {
    case 1: {
      if (disturbed) {
        printf("Heap order has been disturbed due to deletion, insertion will "
               "no more have any effect. Try resetting the heap!\n");
        break;
      }
      int x;
      printf("Enter number: ");
      scanf("%d", &x);
      insert(x);
      size++;
      break;
    }
    case 2: {
      disturbed = 1;
      deleteAndHeapify();
      break;
    }
    case 3: {

      if (size == -1) {
        printf("Heap empty!\n");
      }
      for (int i = 0; i <= size; i++) {
        printf("%d \t", heap[i]);
      }
      break;
    }
    case 4: {
      indx = -1;
      for (int i = 0; i <= size; i++) {
        insert(heap[i]);
      }
      break;
    }
    case 5:
      return 0;
    default: {
      printf("Wrong choice, choose again: \n");
      break;
    }
    }
  }
}
