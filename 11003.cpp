#include <iostream>
#include <deque>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, l; cin >> n >> l;
	deque<pii> dq;
	for (int inp, i = 0; i < n; ++i) {
		cin >> inp;
		// 삽입시 index로 deque 길이 게산
		while (!dq.empty() && dq.front().second + l <= i) dq.pop_front();
		// deque의 front에 최소값을 위치시키기 위함
		while (!dq.empty() && dq.back().first >= inp) dq.pop_back();
		dq.push_back(pii(inp, i));
		cout << dq.front().first << ' ';
	}

	return 0;
}
