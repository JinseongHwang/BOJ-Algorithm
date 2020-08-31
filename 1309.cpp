// 점화식 찾아서 풀이

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	/* 예제(n == 4)
	0마리 => 1
	1마리 => 8
	2마리 => 5 + 5 + 3 + 3 + 2 = 18
	3마리 => 5 + 5 + 2 = 12
	4마리 => 2
	1 + 8 + 18 + 12 + 2 = 41

	n == 0: 1
	n == 1: 3
	n == 2: 7
	n == 3: 17
	n == 4: 41

	점화식 찾기
	f(0) = 1; (n = 0)
	f(1) = 3; (n = 1)
	f(n) = f(n - 1) * 2 + f(n - 2); (n >= 2) */

	int n; cin >> n;
	int dp[(int)1e5 + 5] = { 1, 3, 0, };
	for (int i = 2; i <= n; ++i) dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	cout << dp[n] % 9901 << "\n";

	return 0;
}


// 위 방법은 점화식을 구해내기 힘든 경우가 있기 때문에 그리 좋은 방법은 아니다.
// 따라서 조금 더 dp스럽게 푸는 방법: 각 줄에서 경우의 수를 2차원 dp배열에 저장해 내려가는 방식이다.
#include <iostream>

using namespace std;
const int MAX = 1e5 + 5;
int dp[MAX][3]; // dp[i][ X X | O X | X O ] : 한 줄의 정보

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	dp[0][0] = 1; // 0번째 줄이 X X 일 때 1가지 경우의 수가 있다고 본다.
	for (int i = 1; i <= n; ++i) {
		// 현재 줄이 X X 일 때, 윗 줄이 아무 경우여도 상관없기 때문에 3가지 경우의 수를 모두 더한다.
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		// 현재 줄이 O X 일 때, 윗 줄이 X X 거나 X O 일 수 있으므로 두 경우의 수를 더한다.
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		// 현재 줄이 X O 일 때, 윗 줄이 X X 거나 O X 일 수 있으므로 두 경우의 수를 더한다.
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	// 마지막 줄의 모든 경우의 수를 더한다.
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901 << "\n";

	return 0;
}
