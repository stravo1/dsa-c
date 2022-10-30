#include <stdio.h>

void display(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], int left[], int right[], int len) {

  int size_left = len / 2;
  int size_right = len - size_left;

  int i, j, k;
  i = j = k = 0;

  while (i < size_left &&
         j < size_right) {    // compare each element of each array
    if (left[i] < right[j]) { // if left element is smaller then populate main
                              // array with the left element
      arr[k] = left[i];
      i++;
    } else if (left[i] > right[j]) { // else do the opp
      arr[k] = right[j];
      j++;
    } else { // if they are equal (not keeping duplicate elements)
      arr[k] = left[i];
      i++;
      j++;
    }
    k++;
  }
  while (i < size_left) { // traverse the left-over left array
    arr[k++] = left[i++];
  }
  while (j < size_right) { // traverse the left-over right array
    arr[k++] = right[j++];
  }
}

void mergesort(int arr[], int len) {
  if (len == 1) {
    return;
  }
  int mid = len / 2; // gt the middle of the array

  int left[mid], right[len - mid]; // divide the array into two new arrays

  for (int i = 0; i < mid; i++) { // populate the left sub-array
    left[i] = arr[i];
  }
  for (int i = 0; i < len - mid; i++) { // populate the right sub-array
    right[i] = arr[i + mid];
  }

  mergesort(left, mid);        // mergesort the left sub-array
  mergesort(right, len - mid); // mergesort the right sub-array
  merge(arr, left, right,
        len); // merge the two sorted sub-arrays into the original array
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

  mergesort(arr, size);
  printf("Sorted array:\n");
  display(arr, size);
}
