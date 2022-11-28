#include <stdio.h>

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}
int partition(int start, int end, int arr[]) {
  int pivot = arr[end];    // make the last element the pivot
  int resultIndex = start; // start comparison from start + 1 index

  /* start from the beginning and look till the end
   * everytime you find an element smaller than or equal to the pivot swap that
   * with resultIndex and incrent the resultIndex
   * this ensures all elements
   * before resultIndex id smaller than or equal to pivot
   * */

  for (int i = start; i < end;
       i++) { // loop variant: at each iteration all elements before
              // resultIndex is less than or equal to pivot
    if (arr[i] <= pivot) { // swap a[i] with arr[resultIndex]
      int temp = arr[i];
      arr[i] = arr[resultIndex];
      arr[resultIndex] = temp;
      resultIndex++;
    }
  }

  /* swap pivot with resultIndex */
  int temp = arr[resultIndex];
  arr[resultIndex] = pivot;
  arr[end] = temp;
  return resultIndex;
}

void quick(int start, int end, int arr[]) {
  if (start >= end) {
    return;
  }
  int index = partition(start, end, arr); // get partition index
  quick(start, index - 1, arr);           // sort front partition
  quick(index + 1, end, arr);             // sort rear partition
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

  quick(0, size - 1, arr);
  printf("Sorted array: ");
  display(arr, size);
}
