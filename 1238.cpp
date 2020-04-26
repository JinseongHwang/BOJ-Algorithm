// 1238 파티 - 플로이드 와샬 알고리즘

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define V_MAX 1001
#define INF 1e9
int graph[V_MAX][V_MAX]; // [from][to] = weight

void floyd_warshall(int v) {
	for (int via = 1; via <= v; ++via) {
		for (int row = 1; row <= v; ++row) {
			if (via == row) continue;
			for (int col = 1; col <= v; ++col) {
				if (via == col || row == col || graph[via][col] >= INF || graph[row][via] >= INF) continue;
				if (graph[row][col] > graph[via][col] + graph[row][via]) graph[row][col] = graph[via][col] + graph[row][via];
			}
		}
	}
}
int main() {
	int v, e, x; scanf("%d %d %d", &v, &e, &x); // vertex, edge, party_place
	fill(&graph[0][0], &graph[v][v], INF);
	for (int i = 0; i <= v; ++i) graph[i][i] = 0;

	for (int a, b, c, i = 0; i < e; ++i) { // a: from, b: to, c: weight
		scanf("%d %d %d", &a, &b, &c);
		if (graph[a][b] > c) graph[a][b] = c;
	} // 입력완료

	floyd_warshall(v);

	int max = 0;
	for (int i = 1; i <= v; ++i) // find the largest weight
		if (max < graph[i][x] + graph[x][i]) max = graph[i][x] + graph[x][i];
	
	printf("%d\n", max);
	return 0;
}
