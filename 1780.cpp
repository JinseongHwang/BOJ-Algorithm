#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 2200; // 대략 3^7보다 조금 큰 수
int N, mat[MAX][MAX], result;

void divide(const int symbol, const int sr, const int sc, const int er, const int ec) {
	int len = er - sr + 1;
	for (int row = sr; row <= er; row++) {
		for (int col = sc; col <= ec; col++) {
			if (mat[row][col] != symbol && er - sr >= 2 && ec - sc >= 2) {
				int oneThird = len / 3;
				int twoThird = len / 3 * 2;
				divide(symbol, sr, sc, sr + oneThird - 1, sc + oneThird - 1);
				divide(symbol, sr, sc + oneThird, sr + oneThird - 1, sc + twoThird - 1);
				divide(symbol, sr, sc + twoThird, sr + oneThird - 1, sc + len - 1);
				divide(symbol, sr + oneThird, sc, sr + twoThird - 1, sc + oneThird - 1);
				divide(symbol, sr + oneThird, sc + oneThird, sr + twoThird - 1, sc + twoThird - 1);
				divide(symbol, sr + oneThird, sc + twoThird, sr + twoThird - 1, sc + len - 1);
				divide(symbol, sr + twoThird, sc, sr + len - 1, sc + oneThird - 1);
				divide(symbol, sr + twoThird, sc + oneThird, sr + len - 1, sc + twoThird - 1);
				divide(symbol, sr + twoThird, sc + twoThird, sr + len - 1, sc + len - 1);
				return;
			}
		}
	}
	if (symbol == mat[sr][sc]) result++;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	divide(-1, 0, 0, N - 1, N - 1);
	printf("%d\n", result); result = 0;

	divide(0, 0, 0, N - 1, N - 1);
	printf("%d\n", result); result = 0;

	divide(1, 0, 0, N - 1, N - 1);
	printf("%d\n", result); result = 0;

	return 0;
}
