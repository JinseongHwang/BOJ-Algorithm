#include <iostream>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n; cin >> n;

	priority_queue<int, vector<int>, greater<int> > pq;
	vector<pii> time;

	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		time.push_back(pii(a, b));
	}
	sort(time.begin(), time.end());

	pq.push(time[0].second);
	for (int i = 1; i < n; ++i) {
		if (pq.top() <= time[i].first) {
			pq.pop(); pq.push(time[i].second);
		}
		else pq.push(time[i].second);
	}
	cout << pq.size() << '\n';
	
	return 0;
}
