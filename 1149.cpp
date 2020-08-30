#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1005;
int N;
// dp[i][c]: i번째 집에 c색상으로 칠하는데 최소 비용
// c: 0-Red / 1-Green / 2-Blue
int dp[MAX][3], cost[MAX][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	// 결국 예제처럼 ... R B R ... 과 같이 하나를 뛰어 넘으면 같아도 상관없다.
	// 따라서 앞집이랑만 다르면 된다고 약속하자.
	// bottom-up 방식으로 아래부터 더해나가자.
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	// 세 가지 경우 중 최소값 출력
	cout << min({ dp[N][0], dp[N][1], dp[N][2] }) << "\n";
	
	return 0;
}
