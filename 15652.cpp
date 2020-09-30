#include <cstdio>
using namespace std;

int n, m, arr[10];

void solve(int idx, int k) {
	if (m == k) {
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i <= n; ++i) {
		arr[k] = i;
		solve(i, k + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	solve(1, 0);
	return 0;
}
