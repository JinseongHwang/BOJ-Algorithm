#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
int arr[9];
bool visit[9];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int depth) {
	if (depth == m) {
		int tmp[9] = { 0, };
		copy(arr, arr + m, tmp);
		sort(tmp, tmp + m);
		for (int i = 0; i < m; i++)
			if (arr[i] != tmp[i]) return;

		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		arr[depth] = i;
		dfs(depth + 1);
		visit[i] = false;
	}
}
int main() {
	init();
	cin >> n >> m;
	dfs(0);
	return 0;
}


// 2020-09-19 추가
#include <cstdio>
using namespace std;

int n, m, arr[10];
bool isused[10];

void solve(int k) {
	if (m == k) {
		for (int i = 1; i < m; ++i) if (arr[i - 1] >= arr[i]) return; // 오름차순 검사
		for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			solve(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	solve(0);
	return 0;
}
