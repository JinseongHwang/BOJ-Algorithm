#include <iostream>
#include <string>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n; cin >> n;
	if (n == 1) {
		cout << "666\n";
		return 0;
	}
	else {
		int cnt = 1;
		for (int i = 1666;; ++i) {
			string curr = to_string(i);
			for (int j = 0; j + 2 < curr.length(); ++j) {
				if (curr[j] == '6' && curr[j + 1] == '6' && curr[j + 2] == '6') {
					cnt++; break;
				}
			}
			if (cnt == n) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}
