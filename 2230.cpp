#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

// 처음에 범위를 안보고 INF값을 987654321로 잡아서 틀렸던 문제
const int MAX = 1e5 + 5, INF = 0x7fffffff;
int N, M, arr[MAX];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	if (M == 0) {
		printf("0\n");
		return 0;
	}
	sort(arr, arr + N);

	int L = 0, R = 0, diff = 0, result = INF;
	while (L < N && R <= N) {
		if (diff >= M) {
			if (result > diff) result = diff;
			L++;
			diff = arr[R] - arr[L];
		}
		else { // diff < M
			R++;
			diff = arr[R] - arr[L];
		}
	}
	printf("%d\n", result);

	return 0;
}
