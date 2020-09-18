#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 5, INF = 987654321;
int dp[MAX];

int main() {
	int x; scanf("%d", &x);
	if (x == 1) printf("0\n");
	else if (x <= 3) printf("1\n");
	else {
		fill(dp, dp + x + 1, INF);
		// x가 1, 2, 3일 경우 1번에 가능하다.
		dp[1] = dp[2] = dp[3] = 1;
		for (int i = 4; i <= x; ++i) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
			if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
			if (i % 3 == 0)dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		printf("%d\n", dp[x]);
	}

	return 0;
}
