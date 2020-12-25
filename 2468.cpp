#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

const int MAX = 110;
const int INF = 0x7fffffff;
const int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, -1, 1 };

int N, top, bottom, result;
int graph[MAX][MAX];
bool visited[MAX][MAX];

struct Point {
	int R, C;
};

void DFS(Point curr) {
	visited[curr.R][curr.C] = true;

	for (int i = 0; i < 4; i++) {
		int nxtR = curr.R + dr[i];
		int nxtC = curr.C + dc[i];

		if (nxtR < 0 || nxtR >= N || nxtC < 0 || nxtC >= N) continue;
		if (visited[nxtR][nxtC]) continue;
		
		DFS({ nxtR, nxtC });
	}
}

int safeZones() {
	// visited[i][j] == false인 영역의 개수 구하기
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS({ i, j });
				cnt++;
			}
		}
	}
	
	// initialize
	for (int i = 0; i <= N; i++) {
		memset(visited[i], false, sizeof(visited[i]));
	}

	return cnt;
}

void BFS(Point curr, int H) {
	queue<Point> Q;
	Q.push(curr);

	while (!Q.empty()) {
		int currR = Q.front().R;
		int currC = Q.front().C;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtR = currR + dr[i];
			int nxtC = currC + dc[i];

			if (nxtR < 0 || nxtR >= N || nxtC < 0 || nxtC >= N) continue;
			if (visited[nxtR][nxtC] || graph[nxtR][nxtC] > H) continue;

			Q.push({ nxtR, nxtC });
			visited[nxtR][nxtC] = true;
		}
	}
}

int main() {

	top = result = -1; // 최대값을 도출하기 위함
	bottom = INF; // 최소값을 도출하기 위함

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (top < graph[i][j]) top = graph[i][j];
			if (bottom > graph[i][j]) bottom = graph[i][j];
		}
	}

	if (bottom == top) {
		printf("1\n");
		return 0;
	}

	for (int height = bottom; height <= top; height++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && graph[i][j] <= height) {
					visited[i][j] = true;
					BFS({ i ,j }, height);
				}
			}
		}
		int res = safeZones();
		if (result < res) result = res;

	}

	printf("%d\n", result);

	return 0;
}
