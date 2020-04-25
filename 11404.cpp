// 11404 플로이드 와샬

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define V_MAX 110 // 넉넉하게
#define INF 1e9
int graph[V_MAX][V_MAX]; // [from][to] = weight

int main() {
	int v, e; scanf("%d %d", &v, &e); // 정점의 갯수, 간선의 갯수

	/* 초기 설정 */
	fill(&graph[0][0], &graph[v][v], INF);
	for (int i = 0; i <= v; ++i) graph[i][i] = 0;

	for (int a, b, c, i = 0; i < e; ++i) {
		scanf("%d %d %d", &a, &b, &c); // from, to, weight
		if (graph[a][b] > c) graph[a][b] = c;
	}
	
	/* 갱신 과정 */
	for (int via = 1; via <= v; ++via) { // 몇 번 노드를 거쳐갈 것인지
		for (int row = 1; row <= v; ++row) { // 행
			if (via == row) continue;
			for (int col = 1; col <= v; ++col) { // 열
				if (via == col || row == col || graph[via][col] >= INF || graph[row][via] >= INF) continue;
				if (graph[row][col] > graph[via][col] + graph[row][via]) graph[row][col] = graph[via][col] + graph[row][via];
			}
		}
	}

	/* 출력 */
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (graph[i][j] >= INF) printf("0 ");
			else printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
