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
	llt a, b; cin >> a >> b;
	// a: gcd(x, y), b: lcm = x * y * gcd(x, y)
	// b / a == x * y (x, y is coprime)
	llt mul = b / a; // x * y

	llt r1, r2;
	for (int i = 1; i * i <= mul; ++i) {
		// i가 mul의 약수이고 && mul / i 와 i가 서로소라면
		if (mul % i == 0 && gcd(mul / i, i) == 1) {
			r1 = i; r2 = mul / i;
		}
	}
	cout << r1 * a << ' ' << r2 * a << '\n';

	return 0;
}
