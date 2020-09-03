#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 305;
int adj[MAX][MAX];

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &adj[i][j]);
			adj[i][j] += adj[i][j - 1];
		}
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int sr, sc, er, ec; scanf("%d %d %d %d", &sr, &sc, &er, &ec);
		int sum = 0;
		for (int i = sr; i <= er; ++i) {
			sum += (adj[i][ec] - adj[i][sc - 1]);
		}
		printf("%d\n", sum);
	}

	return 0;
}
