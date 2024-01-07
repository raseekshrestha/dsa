#include <stdio.h>
#include <stdbool.h>

// Recursive function to check if there is a subset with a given sum
bool isSubsetSum(int set[], int n, int sum) {
    // Base cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    // If the last element is greater than the sum, ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    // Recur with or without the last element
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 9;

    if (isSubsetSum(set, n, sum))
        printf("Subset with the given sum exists.\n");
    else
        printf("No subset with the given sum exists.\n");

    return 0;
}
