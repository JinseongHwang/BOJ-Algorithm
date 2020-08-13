#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 소수점 자리수 고정
	cout << fixed;
	cout.precision(1);

	// 기억안나면 printf 쓰자

	int sem; cin >> sem;
	for (int i = 0; i < sem; ++i) {
		int nSub; cin >> nSub;
		int sum1 = 0; double sum2 = 0;
		for (int j = 0; j < nSub; ++j) {
			int u; cin >> u; sum1 += u;
			double v; cin >> v; sum2 += (double)(u * v);
		}
		cout << sum1 << ' ' << (double)sum2 / sum1 << '\n';
	}

	return 0;
}
