#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];
bool isused[10];

void solve(int k) {
	if (m == k) {
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!isused[i]) {
			isused[i] = true;
			arr[k] = list[i]; // 핵심
			solve(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", list + i);
	sort(list, list + n); // 핵심
	solve(0);
	return 0;
}
