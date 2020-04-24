#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 2147483647;
int max_seg[1 << 21], min_seg[1 << 21];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int get_maximum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return max_seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	int result = max(get_maximum(node * 2, start, mid, left, right), 
		get_maximum(node * 2 + 1, mid + 1, end, left, right));
	return result;
}
int get_minimum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return min_seg[node];
	if (end < left || right < start) return INF;
	int mid = (start + end) / 2;
	int result = min(get_minimum(node * 2, start, mid, left, right),
		get_minimum(node * 2 + 1, mid + 1, end, left, right));
	return result;
}
int main() {
	init();
	int N, M; cin >> N >> M;
	const int size = pow(2, (int)log2(N - 1) + 1);
	fill(min_seg, min_seg + (1 << 21), INF);
	for (int i = 0; i < N; i++) {
		int value; cin >> value;
		max_seg[size + i] = value; 
		min_seg[size + i] = value;
	}
	for (int i = size - 1; i > 0; i--) {
		max_seg[i] = max(max_seg[i * 2], max_seg[i * 2 + 1]);
		min_seg[i] = min(min_seg[i * 2], min_seg[i * 2 + 1]);
	} /*포화이진트리 형태 완성*/

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		int max_result = get_maximum(1, 1, size, a, b);
		int min_result = get_minimum(1, 1, size, a, b);
		cout << min_result << " " << max_result << "\n";
	}
	return 0;
}
