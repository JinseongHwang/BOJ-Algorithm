#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];

void solve(int k) {
	if (m == k) {
		for (int i = 1; i < m; ++i) if (arr[i - 1] > arr[i]) return;
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; ++i) {
		arr[k] = list[i];
		solve(k + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", list + i);
	sort(list, list + n);
	solve(0);
	return 0;
}

// 개선된 소스코드
// 80ms -> 4ms

#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, arr[10], list[10];

void solve(int idx, int k) {
	if (k == M) {
		for (int i = 0; i < M; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i < N; ++i) {
		arr[k] = list[i];
		solve(i, k + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", list + i);
	sort(list, list + N);
	solve(0, 0);
	return 0;
}
