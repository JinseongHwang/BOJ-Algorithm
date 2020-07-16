#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

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
		llt a, b; cin >> a >> b;
		if (a < b) swap(a, b);
		cout << (a * b) / gcd(a, b) << "\n";
	}

	return 0;
}
