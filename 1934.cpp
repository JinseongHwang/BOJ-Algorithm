#include <iostream>
using namespace std;
typedef long long int llt;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

llt gcd(llt a, llt b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		llt a, b; cin >> a >> b;
		llt g = gcd(a, b);
		llt l = a * b / g;
		cout << l << "\n";
	}

	return 0;
}
