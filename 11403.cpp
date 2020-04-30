// 11403 경로 찾기 - DFS
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
using namespace std;

#define V_MAX 102
bool graph[V_MAX][V_MAX], result[V_MAX][V_MAX];
bool visit[V_MAX];
int V;

void dfs(int start) {
	for (int i = 0; i < V; ++i) {
		if (graph[start][i] && !visit[i]) {
			visit[i] = true;
			dfs(i);
		}
	}
}
int main() {
	scanf("%d", &V);
	for (int i = 0; i < V; ++i)  // 입력
		for (int j = 0; j < V; ++j)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < V; ++i) { // 연산
		dfs(i);
		int var = 0;
		for (const auto v_res : visit) { // 결과값 입력
			result[i][var++] = v_res; 
		} memset(visit, false, sizeof(bool) * V_MAX); // 다음 케이스를 위해 초기화
	}

	for (int i = 0; i < V; ++i) { // 출력
		for (int j = 0; j < V; ++j)
			printf("%d ", result[i][j]);
		printf("\n");
	}
	return 0;
}
