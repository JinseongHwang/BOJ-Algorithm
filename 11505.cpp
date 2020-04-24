#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
const ll_t MOD = 1e9 + 7;

ll_t seg[1 << 21]; // 2^21

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
ll_t mul(ll_t node, ll_t start, ll_t end, ll_t left, ll_t right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 1;

	ll_t mid = (start + end) / 2;

	ll_t result = mul(node * 2, start, mid, left, right) 
		* mul(node * 2 + 1, mid + 1, end, left, right);
	return result % MOD;
}
int main() {
	init();
	ll_t n, m, k; cin >> n >> m >> k;
	const ll_t sz = pow(2, (ll_t)log2(n - 1) + 1);
	for (ll_t i = 0; i < n; i++)
		cin >> seg[sz + i];
	for (ll_t i = sz - 1; i > 0; i--)
		seg[i] = (seg[i * 2] * seg[i * 2 + 1]) % MOD;
	/* 포화이진트리 구조 완성 */

	for (ll_t i = 0; i < m + k; i++) {
		ll_t a, b, c; cin >> a >> b >> c;
		if (a == 1) { // b번째 수를 c로 바꾼다.
			ll_t node = sz + b - 1;
			seg[node] = c;
			for (node /= 2; node > 0; node /= 2)
				seg[node] = (seg[node * 2] * seg[node * 2 + 1]) % MOD;
		}
		else { // b번째 수부터 c번째 수까지 합을 구하여 출력한다.
			cout << mul(1, 1, sz, b, c) << "\n";
		}
	}
	return 0;
}
