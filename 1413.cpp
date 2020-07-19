// 박스 안의 열쇠

#include <iostream>
using namespace std;
typedef long long int llt;
#define MAX 21
llt dp[MAX][MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

llt gcd(llt a, llt b) {
	return (b == 0) ? a : gcd(b, a % b);
}

llt factorial(llt a) {
	if (a <= 2) return a;
	return a * factorial(a - 1);
}

int main() {
	init();
	llt n, k; cin >> n >> k; // n > k
	for (llt i = 1; i <= n; ++i) {
		for (llt j = 1; j <= n; ++j) {
			if (i == j) {
				dp[i][j] = 1; continue;
			}
			if (j == 1) {
				if (i < 2) dp[i][j] = 1;
				else dp[i][j] = factorial(i - 1);
				continue;
			}
			// 제 1종 스털링 수 점화식
			dp[i][j] = dp[i - 1][j - 1] + ((i - 1) * dp[i - 1][j]);
		}
	}
	/* >> bottom - up 정석적인 풀이 ?
	for (llt i = 1; i <= n; ++i) {
		dp[n][i] += dp[n][i - 1];
	}
	llt g = gcd(dp[n][n], dp[n][k]);
	cout << dp[n][k] / g << '/' << dp[n][n] / g << "\n";*/

	llt ja = 0, mo = 0;
	for (llt i = 1; i <= n; ++i) mo += dp[n][i]; // 모든 경우의 수
	for (llt i = 1; i <= k; ++i) ja += dp[n][i]; // 1부터 k개의 폭탄으로 열쇠를 얻는 경우의 수 합
	llt g = gcd(mo, ja); // 기약분수 형태로 만들기 위함
	cout << ja / g << '/' << mo / g << "\n";

	return 0;
}
