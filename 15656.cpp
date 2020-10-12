#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];

void solve(int k) {
	if (m == k) {
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
