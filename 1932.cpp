// 처음 풀었던 방식

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int sz; cin >> sz;
	vector<vector<pii> > dp; // 메모리 절약을 위해 ragged 형태로 입력받음
	for (int i = 0; i < sz; ++i) {
		vector<pii> v;
		for (int inp, j = 0; j <= i; ++j) {
			cin >> inp;
			v.push_back({ inp, inp });
		}
		dp.push_back(v);
	}

	// 탑다운
	for (int i = 0; i < dp.size() - 1; ++i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			// 두 값이 겹칠땐 더 큰 값으로 갱신
			dp[i + 1][j].second = max(dp[i + 1][j].second, dp[i + 1][j].first + dp[i][j].second);
			dp[i + 1][j + 1].second = max(dp[i + 1][j + 1].second, dp[i + 1][j + 1].first + dp[i][j].second);
		}
	}

	long long int result = 0;
	for (const auto& v : dp[sz - 1]) {
		if (result < v.second) result = v.second;
	}
	cout << result << "\n";

	return 0;
}



// pair타입으로 하지 않아도 된다는걸 알았음
// 다시 풀어봄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int sz; cin >> sz;
	vector<vector<int> > dp; // 메모리 절약을 위해 ragged 형태로 입력받음
	for (int i = 0; i < sz; ++i) {
		vector<int> v;
		for (int inp, j = 0; j <= i; ++j) {
			cin >> inp;
			v.push_back(inp);
		}
		dp.push_back(v);
	}

	// 탑다운
	// 2번째 줄부터 시작하면 pair를 쓰지 않아도 된다.
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			if (j == 0) { // 왼쪽 대각선 위가 없을 때
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == (dp[i].size() - 1)) { // 오른쪽 대각선 위가 없을 때
				dp[i][j] += dp[i - 1][j - 1];
			}
			else { // 두 값이 겹칠땐 더 큰 값으로 갱신
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	long long int result = 0;
	for (const auto& v : dp[sz - 1]) {
		if (result < v) result = v;
	}
	cout << result << "\n";

	return 0;
}
