#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 410, INF = 987654321;
int V, E, graph[MAX][MAX];

void init() {
	for (int i = 0; i <= V; i++) {
		for (int j = 0; j <= V; j++) {
			graph[i][j] = INF;
		}
		graph[i][i] = 0;
	}
}

void floyd() {
	for (int via = 1; via <= V; via++)
		for (int from = 1; from <= V; from++)
			for (int to = 1; to <= V; to++) {
				int curr = graph[from][via] + graph[via][to];
				if (graph[from][to] > curr) graph[from][to] = curr;
			}
}

int main() {
	scanf("%d %d", &V, &E);

	init();

	for (int a, b, c, i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

	floyd();

	int result = INF;
	for (int from = 1; from <= V; from++) {
		for (int to = 1; to <= V; to++) {
			if (from == to) continue;
			int sum = graph[from][to] + graph[to][from];
			if (result > sum) result = sum;
		}
	}
	if (result >= INF) printf("-1\n");
	else printf("%d\n", result);

	return 0;
}
