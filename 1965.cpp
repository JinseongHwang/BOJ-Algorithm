#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1005;
int dp[MAX], cnt[MAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &dp[i]);
	for (int i = 0; i < n; ++i) {
		cnt[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (dp[j] < dp[i]) cnt[i] = max(cnt[i], cnt[j] + 1);
		}
	}
	int result = 0;
	for (int i = 0; i < n; ++i) result = max(result, cnt[i]);
	printf("%d\n", result);

	return 0;
}
