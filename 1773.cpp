#include <iostream>
using namespace std;

const int MAX = 2e6 + 1;
bool showtime[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, c; cin >> n >> c;
	while (n--) {
		int t; cin >> t;
		for (int i = 1; i <= c; ++i) {
			if (i % t == 0) showtime[i] = true;
		}
	}
	int result = 0;
	for (int i = 1; i <= c; ++i) {
		if (showtime[i]) result++;
	}
	cout << result << "\n";

	return 0;
}
