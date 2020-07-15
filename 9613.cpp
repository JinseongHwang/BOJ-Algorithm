#include <iostream>
using namespace std;

#define MAX 101
typedef long long int llt;
int arr[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		llt sum = 0;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
