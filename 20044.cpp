#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 5;
int N, w[MAX], result = 987654321;

int main() {
	scanf("%d", &N);
	register int i; // cpu 연산 속도로?
	for (i = 0; i < N * 2; ++i) scanf("%d", w + i);
	sort(w, w + (N * 2));
	for (i = 0; i < N; ++i) {
		int curr = w[i] + w[(N * 2) - i - 1];
		if (result > curr) result = curr;
	}
	printf("%d\n", result);

	return 0;
}
