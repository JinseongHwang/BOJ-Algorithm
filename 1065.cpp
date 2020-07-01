#include <iostream>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n; cin >> n;
	
	if (n == 1000) n--;
	if (n < 100) {
		cout << n << "\n";
		return 0;
	}
	else { // result + 99
		int cnt = 0;
		for (int i = 111; i <= n; ++i) {
			int each[3] = { 0, }, curr = i;
			each[2] = curr % 10; curr /= 10;
			each[1] = curr % 10; curr /= 10;
			each[0] = curr % 10;
			if (each[2] - each[1] == each[1] - each[0]) cnt++;
		}
		cout << cnt + 99 << "\n";
		return 0;
	}
}
