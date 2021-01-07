#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 1005;
bool visited[MAX];
int graph[MAX];

int DFS(int curr) {
	visited[curr] = true;
	const int nxt = graph[curr];
	if (!visited[nxt]) {
		return DFS(nxt);
	}
	else {
		return curr;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N, result = 0;
		scanf("%d", &N);
		for (int start = 1; start <= N; start++) {
			int end; scanf("%d", &end);
			graph[start] = end;
		}
		for (int start = 1; start <= N; start++) {
			if (!visited[start]) {
				const int lastPos = DFS(start);
				if (graph[lastPos] == start) { // Cycle
					result++;
				}
			}
		}
		printf("%d\n", result);
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
	}
	
	return 0;
}
