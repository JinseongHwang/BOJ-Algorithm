#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10], list[10];
bool isused[10];

void solve(int k) {
	if (m == k) {
		for (int i = 1; i < m; ++i) if (arr[i - 1] > arr[i]) return;
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	int before = 0;
	for (int i = 0; i < n; ++i) {
		if (!isused[i] && (i == 0 || before != list[i])) {
			arr[k] = before = list[i];
			isused[i] = true;
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


// 2020-10-22 다시 풀어봄
// 개선된 코드


#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, arr[10], list[10];
bool isUsed[10];

void solve(int idx, int k) {
	if (k == M) {
		for (int i = 0; i < M; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	int preNode = -1;
	for (int i = idx; i < N; ++i) {
		if (!isUsed[i] && preNode != list[i]) {
			arr[k] = preNode = list[i];
			isUsed[i] = true;
			solve(i + 1, k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", list + i);
	sort(list, list + N);
	solve(0, 0);
	return 0;
}
