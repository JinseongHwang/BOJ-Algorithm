#include <iostream>
#include <vector>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	vector<vector<int>> sum;
	int n, query; cin >> n >> query;
	for (int i = 0; i <= n; ++i) { // 2차원 벡터 resize and initialization
		vector<int> tmp(n + 1, 0);
		sum.push_back(tmp);
	}

	// 구간 합 배열 형태 생성
	for (int i = 1; i <= n; ++i) {
		for (int input, j = 1; j <= n; ++j) {
			cin >> input;
			sum[i][j] = input + sum[i][j - 1];
		}
	}

	for (int x1, y1, x2, y2, i = 0; i < query; ++i) {
		int tmp_sum = 0; // 쿼리의 합계를 저장, 초기화
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; ++j) { 
			tmp_sum += sum[j][y2] - sum[j][y1 - 1]; 
		}
		cout << tmp_sum << "\n";
	}

	return 0;
}
