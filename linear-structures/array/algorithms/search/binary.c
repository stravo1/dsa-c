#include <stdio.h>

int binary(int arr[], int len, int low, int high, int x) {
  if (low <= high) {
    int mid = (high + low) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      return binary(arr, len, mid + 1, high, x);
    } else {
      return binary(arr, len, low, mid - 1, x);
    }

  } else {
    return -1;
  }
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

  int index = binary(arr, size, 0, size - 1, x);

  if (index != -1) {
    printf("Element found at index %d. \n", index);
  } else {
    printf("Element not found. \n");
  }
}
