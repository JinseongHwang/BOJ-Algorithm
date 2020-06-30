#include <iostream>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, m; cin >> n >> m;
	int arr[101] = { 0, };
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int sum = 0, result = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= m) result = max(result, sum);
			}
		}
	}
	cout << result << "\n";

	return 0;
}
