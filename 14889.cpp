
// 백트래킹 문제

#include <bits/stdc++.h>
using namespace std;

int N, abl[21][21], selected[21], result = 987654321;
bool isUsed[21], team[21]; // team[i]: true is team A, false is team B

void solve(int index, int k) {
	if (N / 2 == k) {
		int Aabl = 0, Babl = 0;
		memset(team, false, sizeof(team));
		for (int i = 0; i < k; ++i) team[selected[i]] = true;
		vector<int> A, B;
		for (int i = 1; i <= N; ++i) {
			if (team[i]) A.push_back(i);
			else B.push_back(i);
		}
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A.size(); ++j) {
				Aabl += abl[A[i]][A[j]];
			}
		}
		for (int i = 0; i < B.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				Babl += abl[B[i]][B[j]];
			}
		}
		result = min(result, abs(Aabl - Babl));
	}

	for (int i = index; i <= N; ++i) {
		if (!isUsed[i]) {
			selected[k] = i;
			isUsed[i] = true;
			solve(i + 1, k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) scanf("%d", &abl[i][j]);
	solve(1, 0);
	printf("%d\n", result);

	return 0;
}
