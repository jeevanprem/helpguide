/*1. 0/1 Knapsack
🧠 Core concept

You have items with:

weight[i]
value[i]
Bag capacity = W

For every item, you have 2 choices:

Take it → if it fits
Don't take it

0/1 means: an item can be taken 0 times or 1 time.

DP idea

Define:

dp[i][w] = maximum value using first i items with capacity w

For each item:

Don't take → dp[i-1][w]

Take → value[i-1] + dp[i-1][w-weight[i-1]]

Take maximum.

Algorithm
1. Create dp[n+1][W+1]
2. dp[0][w] = 0
3. dp[i][0] = 0
4. For every item i:
      For every capacity w:
          If weight[i-1] <= w:
              dp[i][w] = max(
                  dp[i-1][w],
                  value[i-1] + dp[i-1][w-weight[i-1]]
              )
          Else:
              dp[i][w] = dp[i-1][w]
5. Answer = dp[n][W]
⭐ Code to remember

This is the important part:

if (weight[i-1] <= w)
    dp[i][w] = max(dp[i-1][w],
                   value[i-1] + dp[i-1][w-weight[i-1]]);
else
    dp[i][w] = dp[i-1][w];
*/

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] +
                               dp[i - 1][w - weight[i - 1]]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}