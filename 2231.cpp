#include <iostream>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n; cin >> n;
	bool found = false;
	for (int i = n / 2; i < n; ++i) {
		int currValue = i, bhh = i;
		while (currValue > 0) {
			bhh += currValue % 10;
			currValue /= 10;
		}
		if (bhh == n) {
			cout << i << "\n";
			found = true;
			break;
		}
	}
	if (!found) cout << "0\n";
	

	return 0;
}
