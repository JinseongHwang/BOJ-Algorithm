// 선물 전달
// 완전순열 == 교란순열
// !n = d(n) 일 때, d(n) = (n - 1) * (d(n - 1) + d(n - 2))
// (n > 0) !1 = 0, !2 = 1, !3 = 2, !4 = 9, !5 = 44, !6 = 265, !7 = 1854 ...

#include <iostream>
using namespace std;
typedef long long int llt;

const llt MOD = 1e9, MAX = 1e6 + 1;
llt dp[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	llt n; cin >> n;
	dp[1] = 0, dp[2] = 1;
	if (n <= 2) {
		cout << dp[n] << "\n";
		return 0;
	}

	for (int i = 3; i <= n; ++i) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n] << "\n";

	return 0;
}
