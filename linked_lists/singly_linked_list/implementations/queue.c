#include "linked_list.c"

/* the above line imports all the required structures and functions from the
 * linked_list.c file */

int main() {
  while (1 > 0) {
    int i;
    printf("1. Enqueue \n2. Display \n3. Dequeue\n4. Exit\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      printf("Enter number: ");
      scanf("%d", &i);
      insert_end(i);
      break;
    }
    case 2: {
      if (!head) {
        printf("Queue empty!\n");
        break;
      }
      display();
      break;
    }
    case 3: {
      if (!head) {
        printf("Queue empty!\n");
        break;
      }
      int k = delete_first();
      printf("Dequeued element: %d\n", k);
      break;
    }
    case 4:
      exit(1);
    default:
      printf("Choose again\n");
    }
  }
}
