#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll_t;
ll_t seg[1 << 21];
ll_t N, M;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
ll_t sum(ll_t node, ll_t start, ll_t end, ll_t left, ll_t right) {
	if (left <= start && right >= end) return seg[node];
	if (end < left || start > right) return 0;
	ll_t mid = (start + end) / 2;
	ll_t result = sum(node * 2, start, mid, left, right)
		+ sum(node * 2 + 1, mid + 1, end, left, right);
	return result;
}
int main() {
	init();
	cin >> N >> M;
	const ll_t size = pow(2, (ll_t)log2(N) + 1);
	for (int i = 0; i < M; i++) {
		bool query; ll_t arg1, arg2;
		/* query 0 -> SUM / query 1 -> MODIFY */
		cin >> query >> arg1 >> arg2;
		if (!query) {
			if (arg1 > arg2) swap(arg1, arg2);
			cout << sum(1, 1, size, arg1, arg2) << "\n";
		}
		else {
			ll_t node = size + arg1 - 1;
			ll_t diff = arg2 - seg[node];
			for (; node > 0; node /= 2) seg[node] += diff;
		}
	}
	return 0;
}
