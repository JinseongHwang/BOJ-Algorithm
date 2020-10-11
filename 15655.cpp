#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];
bool isused[10];

void solve(int k) {
	if (m == k) {
		for (int i = 1; i < m; ++i) if (arr[i - 1] >= arr[i]) return;
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!isused[i]) {
			isused[i] = true;
			arr[k] = list[i];
			solve(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", list + i);
	sort(list, list + n);
	solve(0);
	return 0;
}


// 개선된 조합

#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];
bool isused[10];

void solve(int idx, int k) {
	if (k == m) {
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i < n; ++i) {
		if (!isused[i]) {
			arr[k] = list[i];
			isused[i] = true;
			solve(i + 1, k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", list + i);
	sort(list, list + n);
	solve(0, 0);
	return 0;
}
