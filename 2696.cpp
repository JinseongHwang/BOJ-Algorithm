#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, less<int> > maxh;
priority_queue<int, vector<int>, greater<int> > minh;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		cout << n / 2 + 1 << '\n';
		for (int inp, i = 0; i < n; ++i) {
			cin >> inp;
			if (i % 2 == 0) maxh.push(inp);
			else minh.push(inp);

			if (!maxh.empty() && !minh.empty() && maxh.top() > minh.top()) {
				int maxtop = maxh.top(), mintop = minh.top();
				maxh.pop(); minh.pop();
				maxh.push(mintop); minh.push(maxtop);
			}

			if (i % 2 == 0) {
				cout << maxh.top() << ' ';
				// if (i > 0 && i % 18 == 0 && i != (n - 1)) cout << '\n';
			}
		}
		// cout << '\n';
		while (!maxh.empty()) maxh.pop();
		while (!minh.empty()) minh.pop();
	}

	return 0;
}
