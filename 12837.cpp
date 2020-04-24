#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
ll_t seg[1 << 21];

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
	int N, Q; cin >> N >> Q;
	const ll_t size = pow(2, (ll_t)log2(N - 1) + 1);
	for (int i = 0; i < Q; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			ll_t node = size + b - 1;
			for (; node > 0; node /= 2) seg[node] += c;
		}
		else cout << sum(1, 1, size, b, c) << "\n";
	}
	return 0;
}
