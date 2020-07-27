#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, result;
priority_queue<int, vector<int>, less<int> > maxh;
priority_queue<int, vector<int>, greater<int> > minh;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> n;
	for (int inp, i = 0; i < n; ++i) {
		cin >> inp;
		// maxh에 가운데값보다 작은 값들이 들어가야하고,
		// minh에 가운데값보다 큰 값들이 들어가야한다.
		if (i % 2 == 0) maxh.push(inp);
		else minh.push(inp);

		// 위 조건을 만족하지 않으면 두 힙의 최상위 값을 교환한다.
		if (!maxh.empty() && !minh.empty() && maxh.top() > minh.top()) {
			int maxtop = maxh.top(), mintop = minh.top();
			maxh.pop(); minh.pop();
			maxh.push(mintop); minh.push(maxtop);
		}

		if (maxh.empty()) result = minh.top();
		else if (minh.empty()) result = maxh.top();
		else result = min(maxh.top(), minh.top());
		cout << result << '\n';
	}

	return 0;
}
