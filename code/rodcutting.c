/*
3. Rod Cutting
🧠 Core concept

Rod of length n.

For every possible first cut:

price[cut] + best remaining piece

We try all possible first cuts and take maximum.

DP definition
dp[i] = maximum price obtainable from rod of length i

Formula:

dp[i] = max(price[j] + dp[i-j])

where:

j = 1 to i
⭐ Most important line
dp[i] = max(dp[i], price[j-1] + dp[i-j]);
Algorithm
dp[0] = 0

for i = 1 to n:
    dp[i] = 0

    for j = 1 to i:
        dp[i] = max(dp[i],
                    price[j-1] + dp[i-j])
*/ 

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;

    printf("Enter rod length: ");
    scanf("%d", &n);

    int price[n];

    printf("Enter prices for lengths 1 to %d:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    int dp[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;

        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i],
                        price[j - 1] + dp[i - j]);
        }
    }

    printf("Maximum revenue = %d\n", dp[n]);

    return 0;
}

/*Enter rod length: 8
Enter prices for lengths 1 to 8:
1 5 8 9 10 17 17 20

Maximum revenue = 22*/