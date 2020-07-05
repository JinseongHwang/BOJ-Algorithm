// 2606 바이러스 - DFS
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

#define V_MAX 101
bool graph[V_MAX][V_MAX];
bool visit[V_MAX];
int V, E;
int count = 0;

void dfs(int start) {
	visit[start] = true; count++;
	for (int col = 1; col <= V; ++col) {
		if (graph[start][col] && !visit[col]) {
			/*연결이 되어있으며, 방문한 적 없음*/
			dfs(col);
		}
	}
}

int main() {
	scanf("%d %d", &V, &E); // Vertex, Edge
	for (int i = 0; i < E; ++i) { // 양방향 그래프
		int a, b; scanf("%d %d", &a, &b);
		graph[a][b] = true;
		graph[b][a] = true;
	}
	dfs(1); // start node number is 1
	printf("%d\n", --count);
	return 0;
}
