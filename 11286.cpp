#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	int n; cin >> n;
	while (n--) {
		int inp; cin >> inp;
		if (inp != 0) {
			if (inp < 0) pq.push(pii(abs(inp), -1));
			else pq.push(pii(inp, 1));
		}
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top().first * pq.top().second << '\n'; pq.pop();
			}
		}
	}

	return 0;
}
