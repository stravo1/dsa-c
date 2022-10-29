#include "linked_list.c"

/* the above line imports all the required structures and functions from the
 * linked_list.c file */

int main() {
  while (1 > 0) {
    int i;
    printf("1. Push \n2. Display \n3. Pop\n4. Exit\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      printf("Enter number: ");
      scanf("%d", &i);
      insert_first(i);
      break;
    }
    case 2: {
      if (!head) {
        printf("Stack empty!\n");
        break;
      }
      display();
      break;
    }
    case 3: {
      if (!head) {
        printf("Stack empty!\n");
        break;
      }
      int k = delete_first();
      printf("Popped element: %d", k);
      break;
    }
    case 4:
      exit(1);
    default:
      printf("Choose again\n");
    }
  }
}
