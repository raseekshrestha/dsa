#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex < k) {
            return quickselect(arr, pivotIndex + 1, high, k);
        } else {
            return quickselect(arr, low, pivotIndex - 1, k);
        }
    }

    return -1; // Error value for invalid input
}

int order_statistics(int arr[], int size, int k) {
    if (k > 0 && k <= size) {
        return quickselect(arr, 0, size - 1, k - 1);
    } else {
        return -1; // Error value for invalid input
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = order_statistics(arr, size, k);
    
    if (result != -1) {
        printf("%d-th smallest element is: %d\n", k, result);
    } else {
        printf("Invalid input for k\n");
    }

    // Empirical analysis
    int input_sizes[] = {10,100,1000,1000000};
    
    for (int i = 0; i < sizeof(input_sizes) / sizeof(input_sizes[0]); i++) {
        int random_arr[input_sizes[i]];

        for (int j = 0; j < input_sizes[i]; j++) {
            random_arr[j] = rand() % (input_sizes[i] * 10);
        }

        clock_t start_time = clock();
        order_statistics(random_arr, input_sizes[i], k);
        clock_t end_time = clock();
        double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("For size %d, execution time: %f seconds\n", input_sizes[i], execution_time);
    }

    return 0;
}
