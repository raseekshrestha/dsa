#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int n, int amount, int selectedCoins[]) {
    int dp[amount + 1];

    // Initialize the table with INT_MAX (representing infinity)
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Base case: 0 coins needed to make change for 0
    dp[0] = 0;

    // Build the table bottom-up
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int subproblem = dp[i - coins[j]];
                if (subproblem != INT_MAX && subproblem + 1 < dp[i]) {
                    dp[i] = subproblem + 1;
                    // Keep track of the selected coin
                    selectedCoins[i] = coins[j];
                }
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

void printSelectedCoins(int selectedCoins[], int amount) {
    printf("Selected coins: ");
    while (amount > 0) {
        printf("%d ", selectedCoins[amount]);
        amount -= selectedCoins[amount];
    }
    printf("\n");
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &amount);

    int selectedCoins[amount + 1];
    int result = minCoins(coins, n, amount, selectedCoins);

    if (result == -1) {
        printf("It is not possible to make change for the given amount.\n");
    } else {
        printf("Minimum number of coins needed: %d\n", result);
        printSelectedCoins(selectedCoins, amount);
    }

    return 0;
}
