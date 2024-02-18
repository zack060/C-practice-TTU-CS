#include <stdio.h>


void inputArray(int *arr,int size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", arr+i);
  }
}


void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr+i));
  }
  printf("\n");
}

void swapArray(int *sourceArr, int *destArr, int size) {
  for (int i = 0; i < size; i++) {
    int tmp = *(destArr+i);
    *(destArr+i) = *(sourceArr+i);
    *(sourceArr+i) = tmp;
  }
}

int main(void) {
  int size;

  printf("Enter size of an array: ");
  scanf("%d", &size);

  int sourceArr[size];
  int destArr[size];

  printf("Enter %d elements in the source array:\n", size);
  inputArray(sourceArr, size);

  printf("Enter %d elements in the destination array:\n", size);
  inputArray(destArr,size);

  printf("\nSource array before swapping: ");
  printArray(sourceArr, size);
  printf("Destination array before swapping:");
  printArray(destArr, size);

  swapArray(sourceArr, destArr, size);

  printf("\nSource array after swapping: ");
  printArray(sourceArr, size);
  printf("Destination array after swapping: ");
  printArray(destArr, size);

  printf("\n");
  return 0;

}
