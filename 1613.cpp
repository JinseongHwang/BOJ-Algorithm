// #1613 역사

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 410, INF = 987654321;
int N, K, Q;
// dist[i][j]: 값이 INF가 아니라면 갈 수 있음(이후에 발생), INF라면 못감(이전에 발생했거나 유추 불가)
int dist[MAX][MAX];

void floyd_warshall() {
	for (int via = 1; via <= N; ++via)
		for (int from = 1; from <= N; ++from)
			for (int to = 1; to <= N; ++to)
				dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; ++i) fill(dist[i], dist[i] + N + 1, INF);

	for (int i = 0; i < K; ++i) {
		int from, to; scanf("%d %d", &from, &to);
		dist[from][to] = 1;
	}
	floyd_warshall();

	scanf("%d", &Q);
	while (Q--) {
		int a, b; scanf("%d %d", &a, &b);
		if (dist[a][b] != INF) printf("-1\n");
		else if (dist[b][a] != INF) printf("1\n");
		else printf("0\n");
	}

	return 0;
}
