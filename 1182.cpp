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
