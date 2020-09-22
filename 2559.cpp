#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 5;
int N, K, L, R, sum, arr[MAX], result = -987654321;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", arr + i);
		if (i < K) sum += arr[i];
	}

	L = 0, R = K - 1;
	if (result < sum) result = sum;
	while (N > R + 1) {
		sum -= arr[L];
		L++; R++;
		sum += arr[R];
		if (result < sum) result = sum;
	}
	printf("%d\n", result);

	return 0;
}
