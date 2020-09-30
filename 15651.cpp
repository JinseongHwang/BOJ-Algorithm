#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[depth] = i;
		dfs(depth + 1);
	}
}
int main() {
	init();
	cin >> n >> m;

	dfs(0);

	return 0;
}

// 2020-10-01 추가
#include <cstdio>
using namespace std;

int n, m, arr[10];

void solve(int k) {
	if (m == k) {
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i) {
		// 중복 조건이 빠진 것이 핵심
		arr[k] = i;
		solve(k + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	solve(0);
	return 0;
}
