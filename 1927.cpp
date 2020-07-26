#include <iostream>
#include <queue>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	priority_queue<int, vector<int>, greater<int> > pq;
	int n; cin >> n;
	while (n--) {
		int inp; cin >> inp;
		if (inp) {
			pq.push(inp);
		}
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n"; pq.pop();
			}
		}
	}

	return 0;
}
