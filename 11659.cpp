#include <iostream>
#include <vector>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int size, query; cin >> size >> query;
	vector<int> sum(size + 1, 0); // 구간의 시작을 1로 맞추기 위해서
	for (int input, i = 1; i <= size; ++i) {
		cin >> input;
		sum[i] = input + sum[i - 1];
	}

	for (int from, to, i = 0; i < query; ++i) {
		cin >> from >> to;
		cout << sum[to] - sum[from - 1] << "\n";
	}

	return 0;
}
