#include <stdio.h>

void insertion(int arr[], int len, int gap) { // generalized insertion sort
  for (int i = gap; i < len; i++) {           // next element of the sub-file
    int t = arr[i];
    int j;
    for (j = i - gap; j >= 0 && t < arr[j];
         j -= gap) { // compare elemets of the sub-file
      arr[j + gap] = arr[j];
    }
    arr[j + gap] = t;
  }
}

void shell(int arr[], int len) {
  int gap[] = {7, 5, 3, 1}; // array of gap values

  for (int i = 0; i < 4; i++) { // itertate through the gap values
    insertion(arr, len, gap[i]);
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

  shell(arr, size);

  printf("Sorted array: \n");
  for (int i = 0; i < size; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
