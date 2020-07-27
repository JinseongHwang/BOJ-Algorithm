#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
typedef long long int llt;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, k; cin >> n >> k;
	priority_queue<llt, vector<llt>, greater<llt> > pq;
	vector<llt> v;

	for (llt inp, i = 0; i < n; ++i) {
		cin >> inp; 
		v.push_back(inp);
		pq.push(inp);
	}

	k--;
	while (k--) {
		llt curr = pq.top();
		pq.pop();
		for (const auto& a : v) {
			llt mul = curr * a; 
			pq.push(mul); // 소수의 곱 push
			if (curr % a == 0) break; // 중복 제거
		}
	}
	cout << pq.top() << '\n';

	return 0;
}
