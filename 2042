#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
ll_t sz;
ll_t seg[1 << 21]; // 2^21

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
ll_t sum(ll_t node, ll_t start, ll_t end, ll_t left, ll_t right) {
	// 1, 1, 8, 2, 5

	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;

	ll_t mid = (start + end) / 2;

	return sum(node * 2, start, mid, left, right)
		+ sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
	init();
	ll_t n, m, k; cin >> n >> m >> k; 
	sz = pow(2, (ll_t)log2(n - 1) + 1); 
	for (ll_t i = 0; i < n; i++)
		cin >> seg[sz + i];
	for (ll_t i = sz - 1; i > 0; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	/* 포화이진트리 구조 완성 */

	for (ll_t i = 0; i < m + k; i++) {
		ll_t a, b, c; cin >> a >> b >> c; 
		ll_t node, diff;
		if (a == 1) { // b번째 수를 c로 바꾼다.
			node = sz + b - 1; 
			diff = c - seg[node]; 
			for (; node > 0; node /= 2)
				seg[node] += diff;
		}
		else { // b번째 수부터 c번째 수까지 합을 구하여 출력한다.
			cout << sum(1, 1, sz, b, c) << "\n";
		}
	}
	return 0;
}
