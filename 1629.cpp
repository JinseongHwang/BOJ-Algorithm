#include <iostream>
typedef long long int llt;
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

// 10^11 -> ((10^5) * 10)^2 -> (((10^2) * 10)^2 * 10)^2
// 10^4 -> (10^2)^2
llt mypow(llt a, llt b, llt c) {
	if (b == 0) return 1;
	else {
		llt tmp = mypow(a, b / 2, c);
		if (b % 2 == 0) return (tmp * tmp) % c;
		else return ((tmp * tmp) % c) * a % c;
	}
}

int main() {
	init();
	llt a, b, c; cin >> a >> b >> c;
	cout << mypow(a, b, c) << "\n";

	return 0;
}
