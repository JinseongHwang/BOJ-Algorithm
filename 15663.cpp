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
	
	int before = 0; // 현재 depth(k)에서 같은 원소값을 가질 경우 무시한다.
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


// 2020-10-21 다시 풀어봄


#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, arr[10], list[10];
bool isUsed[10];

void solve(int k) {
	if (k == M) {
		for (int i = 0; i < M; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	int preNode = -1;
	for (int i = 0; i < N; ++i) {
		if (!isUsed[i] && preNode != list[i]) {
			arr[k] = list[i];
			preNode = list[i];
			isUsed[i] = true;
			solve(k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", list + i);
	sort(list, list + N);
	solve(0);
	return 0;
}
