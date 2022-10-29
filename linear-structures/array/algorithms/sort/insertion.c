#include <stdio.h>

void insertion(int arr[], int len) {
  for (int i = 1; i < len; i++) {
    int t = arr[i];
    int j;
    for (j = i - 1; j >= 0 && t < arr[j]; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = t;
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

  insertion(arr, size);
}
