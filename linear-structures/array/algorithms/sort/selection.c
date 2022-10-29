#include <stdio.h>

void selection(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] > arr[j]) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
  printf("Sorted array: \n");
  for (int i = 0; i < len; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
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

  selection(arr, size);
}
