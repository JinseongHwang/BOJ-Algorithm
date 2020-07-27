#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int n; cin >> n;
	if (n == 1) {
		cout << "0\n";
		return 0;
	}
	int num_cards[MAX] = { 0, };
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> num_cards[i];
		pq.push(num_cards[i]);
	}
	int result = 0;
	while (1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		result += (a + b);
		if (pq.empty()) break;
		pq.push(a + b);
	}
	cout << result << "\n";

	return 0;
}


// =========
// 2020-07-27 추가

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	priority_queue<int, vector<int>, greater<int> > pq;
	int n; cin >> n;
	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	for (int inp, i = 0; i < n; ++i) {
		cin >> inp;
		pq.push(inp);
	}

	int result = 0;
	while (1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int sum = a + b;
		result += sum;
		if (pq.empty()) break;
		pq.push(sum);
	}
	cout << result << '\n';

	return 0;
}
