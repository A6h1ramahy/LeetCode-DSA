int change(int amount, int* coins, int coinsSize) {
    unsigned long long *dp = calloc(amount + 1, sizeof(unsigned long long));

    dp[0] = 1;

    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    int ans = (int)dp[amount];
    free(dp);

    return ans;
}
