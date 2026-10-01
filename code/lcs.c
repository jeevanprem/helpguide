/*
5. Longest Common Subsequence — LCS
🧠 Core concept

Given two strings:

ABCBDAB
BDCABA

Find longest sequence that appears in both without changing order.

DP definition
dp[i][j] =
LCS length of first i characters of X
and first j characters of Y
Main logic ⭐

If characters match:

dp[i][j] = dp[i-1][j-1] + 1

If they don't:

dp[i][j] = max(dp[i-1][j],
               dp[i][j-1])
               */
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] =
                    dp[i - 1][j - 1] + 1;

            else
                dp[i][j] =
                    max(dp[i - 1][j],
                        dp[i][j - 1]);
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    return 0;
}

/*
Enter first string: ABCBDAB
Enter second string: BDCABA

Length of LCS = 4
*/