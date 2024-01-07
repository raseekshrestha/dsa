#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int i = n, w = capacity;
    printf("Items included in the knapsack:\n");
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d (Value: %d, Weight: %d)\n", i, values[i - 1], weights[i - 1]);
            w = w - weights[i - 1];
            i--;
        } else {
            i--;
        }
    }
    return dp[n][capacity];
}

int main() {
    int values[MAX], weights[MAX];
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the values and weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(values, weights, n, capacity);
    printf("Maximum value of items that can be included in the knapsack: %d\n", maxValue);

    return 0;
}
