#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum { PRE, CURR };

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, result = -1e8 - 1;
	cin >> n;

	int sum[2] = { 0, }; // sum[PRE]: 이전까지의 합, sum[CURR]: 현재 합
	vector<int> input(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> input[i]; // 입력받음
	
	for (int i = 1; i <= n; ++i) { // 구간 합 시작지점
		sum[CURR] = max(sum[PRE] + input[i], input[i]);
		if (result < sum[CURR]) result = sum[CURR];
		sum[PRE] = sum[CURR];
	}
	cout << result << "\n";

	return 0;
}
