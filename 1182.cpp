#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int N, S, result = 0, sum = 0;
int arr[20];
void dfs(int depth) {
	if (depth == N) return;
	if (sum + arr[depth] == S) result++;
	dfs(depth + 1);
	sum += arr[depth];
	dfs(depth + 1);
	sum -= arr[depth];
}
int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);
	dfs(0);
	printf("%d\n", result);
	return 0;
}


// 2020-07-04 추가
// 또다른 풀이
#include <iostream>
using namespace std;

int arr[21], n, s, result;
bool check[21];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void dfs(int index, int count, int limit) {
	if (count == limit) {
		int sum = 0;
		for (int i = 0; i < 21; ++i) {
			if (check[i]) sum += arr[i];
		}
		if (sum == s) result++;
	}
	for (int i = index; i < n; ++i) {
		if (check[i]) continue;
		check[i] = true;
		dfs(i, count + 1, limit);
		check[i] = false;
	}
}

int main() {
	init();
	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 1; i <= n; ++i) dfs(0, 0, i);
	cout << result << "\n";
	
	return 0;
}


// 2020-11-04 추가

// 백트래킹 조합
// 내 소스인데 훨씬 빠름
// -> http://boj.kr/57222f5255aa4a9d98e55ae1e0f90838

#include <bits/stdc++.h>
using namespace std;

int N, S, arr[20], selected[20], result, tmpSum;
bool isUsed[20];

void solve(int nSelect, int index, int depth) {
	if (depth == nSelect) {
		tmpSum = 0;
		for (int i = 0; i < nSelect; ++i) tmpSum += selected[i];
		if (tmpSum == S) result++;
		return;
	}

	for (int i = index; i < N; ++i) {
		if (!isUsed[i]) {
			selected[depth] = arr[i];
			isUsed[i] = true;
			solve(nSelect, i + 1, depth + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	for (int i = 1; i <= N; ++i) solve(i, 0, 0);
	printf("%d\n", result);

	return 0;
}
