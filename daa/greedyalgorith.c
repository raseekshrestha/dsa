#include <stdio.h>

void greedyCoinChange(int coins[], int n, int amount) {
    int coinCount = 0;

    printf("Selected coins: ");

    // Start with the largest denomination and greedily select coins
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCount++;
            printf("%d ", coins[i]);
        }
    }

    printf("\nTotal number of coins used: %d\n", coinCount);
}

int main() {
    int coins[] = {25, 10, 5, 1};
    printf("Available Currency:\n");

    int n = sizeof(coins) / sizeof(coins[0]);
    for (int i=0;i<n;i++){
        printf("%d  ",coins[i]);
    }

    int amount;
    printf("\nEnter the amount for which you want to make change: ");
    scanf("%d", &amount);

    greedyCoinChange(coins, n, amount);

    return 0;
}
