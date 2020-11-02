
// N과 M이랑 비슷함
// 백트래킹으로 조합 뽑는 문제

#include <bits/stdc++.h>
using namespace std;

int n, selected[6], arr[15];
bool isUsed[15];

void myPermutation(int index, int depth) {
	if (depth == 6) {
		for (const int& elem : selected) printf("%d ", elem);
		printf("\n");
		return;
	}

	for (int i = index; i < n; ++i) {
		if (!isUsed[i]) {
			selected[depth] = arr[i];
			isUsed[i] = true;
			myPermutation(i + 1, depth + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < n; ++i) scanf("%d", arr + i);
		myPermutation(0, 0);
		printf("\n");

		memset(selected, 0, sizeof(selected));
		memset(arr, 0, sizeof(arr));
		memset(isUsed, 0, sizeof(isUsed));
	}
	
	return 0;
}
