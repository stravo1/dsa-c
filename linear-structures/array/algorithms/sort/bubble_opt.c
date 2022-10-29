#include <stdio.h>

void bubble(int arr[], int len) {
  int flag = 1;
  for (int i = 0; i < len && flag; i++) {
    flag = 0;
    for (int j = 0; j < len - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
        flag = 1;
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

  bubble(arr, size);
}
