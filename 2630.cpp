#include <cstdio>
using namespace std;

const int MAX = 1 << 7;
int paper[MAX][MAX], cnt[2];

void DQ(int sr, int sc, int er, int ec, int symbol) {
	for (int i = sr; i <= er; ++i) {
		for (int j = sc; j <= ec; ++j) {
			if (paper[i][j] != symbol) { // 분할 해야함
				int mr = (sr + er) / 2, mc = (sc + ec) / 2;
				DQ(sr, sc, mr, mc, paper[sr][sc]); // 좌상
				DQ(sr, mc + 1, mr, ec, paper[sr][mc + 1]); // 우상
				DQ(mr + 1, sc, er, mc, paper[mr + 1][sc]); // 좌하
				DQ(mr + 1, mc + 1, er, ec, paper[mr + 1][mc + 1]); // 우하
				return;
			}
		}
	}
	cnt[symbol]++;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &paper[i][j]);
	DQ(0, 0, n - 1, n - 1, paper[0][0]);
	printf("%d\n%d\n", cnt[0], cnt[1]);
	return 0;
}
