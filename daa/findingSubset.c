#include <stdio.h>

#define MAX 100

void findSubset(int s[], int n, int d, int currentSum, int index, int subset[], int subsetSize) {
    if (currentSum == d) {
        // Print the subset
        printf("Subset found: [");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d", subset[i]);
            if (i < subsetSize - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        return;
    }

    if (index == n || currentSum > d) {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = s[index];
    findSubset(s, n, d, currentSum + s[index], index + 1, subset, subsetSize + 1);

    // Exclude the current element from the subset
    findSubset(s, n, d, currentSum, index + 1, subset, subsetSize);
}

int main() {
    int s[] = {1,2,4,5,6,7,8};
    int n = sizeof(s)/sizeof(int), d=10;

    printf("Target: %d\n",d);

    int subset[MAX];
    findSubset(s, n, d, 0, 0, subset, 0);

    if (subset[0] == 0) {
        printf("No solution found.\n");
    }

    return 0;
}
