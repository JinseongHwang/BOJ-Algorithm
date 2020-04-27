#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 1001
const int DIV = 1e4 + 7;
int dp[SIZE][SIZE];

int combination(int n, int k) {
	dp[1][0] = 1, dp[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] % DIV) + (dp[i - 1][j] % DIV);
			dp[i][j] %= DIV;
		}
	}
	return dp[n][k];
}
int main() {
	int n, k; scanf("%d %d", &n, &k);
	if (n - k <= n / 2) k = n - k;
	printf("%d\n", combination(n, k));
	return 0;
}
