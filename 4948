#include <iostream>
using namespace std;
#define MAX 246913
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	while (1) {
		int n, result = 0;
		cin >> n;
		if (!n) break;

		bool isPrime[MAX] = { 0, }; isPrime[1] = true;
		for (int i = 2; i <= n * 2; i++) {
			if (isPrime[i] == true) continue;
			for (int j = i * 2; j <= n * 2; j += i) {
				isPrime[j] = true;
			}
		}
		for (int i = n + 1; i <= n * 2; i++) {
			if (isPrime[i] == false) result++;
		}
		cout << result << "\n";
	}
	return 0;
}
