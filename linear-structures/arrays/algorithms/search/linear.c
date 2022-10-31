#include <stdio.h>

int linear(int arr[], int len, int x) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int size, x;

  printf("Enter size of array: ");
  scanf("%d", &size);

  int arr[size];
  for (int i = 0; i < size; i++) {
    int temp;
    printf("Enter element %d: ", i + 1);
    scanf("%d", &temp);
    arr[i] = temp;
  }

  printf("Enter element to be searched: ");
  scanf("%d", &x);

  int index = linear(arr, size, x);

  if (index != -1) {
    printf("Element found at index %d. \n", index);
  } else {
    printf("Element not found. \n");
  }
}
