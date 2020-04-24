#include <iostream>
using namespace std;
void init() {
	ios_base::sync_with_stdio;
	cout.tie(0);
	cin.tie(0);
}
int main() {
	init();
	int M, N, sum = 0, min;
	bool isPrime[10001] = { 0, }; isPrime[1] = true;
	cin >> M >> N; min = N;
	for (int i = 2; i <= N; i++) {
		if (isPrime[i] == true) continue;
		for (int j = i * 2; j <= N; j += i) {
			isPrime[j] = true;
		}
	}
	for (int i = M; i <= N; i++) {
		if (!isPrime[i]) {
			sum += i;
			if (min > i) min = i;
		}
	}
	if (!sum) cout << "-1\n";
	else cout << sum << "\n" << min << "\n";
	return 0;
}
