#include <stdio.h>
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
int main() {
  int data[] = {23,42,32,1,35};
  int size = sizeof(data) / sizeof(data[0]);
  printf("Before sorting\n");
  for(int i=0;i<size;i++){
  	printf("%d ",data[i]);
  }
  insertionSort(data, size);
  printf("\nAfter sorting:\n");
  printArray(data, size);
  return 0;
}
