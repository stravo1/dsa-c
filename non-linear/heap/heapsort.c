#include <stdio.h>
#define HEAP_SIZE 20

int heap[HEAP_SIZE], size = 0;

void swap(int old, int new) { // swap two positions in the heap
  int temp = heap[old];
  heap[old] = heap[new];
  heap[new] = temp;
}

void trickleDownRoot(int pos) {
  /*
   * given a binary tree in which all the levels
   * except the top level (root) follow the heap
   * structure, this function 'trickles down' the root node to its required
   * position so that the entire tree becomes a heap
   *
   */

  int parent = pos;

  while (parent * 2 + 1 < size) { // until we reach the end of the heap

    int leftChild = parent * 2 + 1;
    int rightChild = leftChild + 1;

    int largest = parent;

    /* find the largest key among the parent, left and right child (provided
     * they are within the range) */
    if (leftChild < size && heap[leftChild] > heap[largest]) {
      largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest]) {
      largest = rightChild;
    }
    if (largest == parent) {
      return; // if the parent is the largest then it follows the heap structure
    }
    swap(parent, largest); // swap with the larger child
    parent = largest;
  }
}

void heapSort() {
  for (int i = size - 1; i >= 0; i--) {
    printf("%d \t", heap[0]);
    swap(i, 0); // swap root with the last item in heap
    size--;
    trickleDownRoot(0); // fix the heap
  }
  printf("\n");
}

void convertHeap() {
  /* function to convert any array to heap */
  for (int i = size / 2 - 1; i >= 0;
       i--) { // start from the 2nd last level (above the leaf nodes) and go
              // upwards
    trickleDownRoot(i); // keep fixing the array to heap one level at a time
  }
}

int main() {
  while (1) {
    int inp;
    printf("\n1. Insert \n2. Heap Sort \n3. View \n4. Exit "
           "\n\n");
    scanf("%d", &inp);
    switch (inp) {
    case 1: {
      int x;
      printf("Enter number: ");
      scanf("%d", &x);
      heap[size] = x;
      size++;
      convertHeap();
      break;
    }
    case 2: {
      heapSort();
      break;
    }
    case 3: {

      if (size == 0) {
        printf("Heap empty!\n");
      }
      for (int i = 0; i < size; i++) {
        printf("%d \t", heap[i]);
      }
      printf("\n");
      break;
    }
    case 4:
      return 0;
    default: {
      printf("Wrong choice, choose again: \n");
      break;
    }
    }
  }
}
