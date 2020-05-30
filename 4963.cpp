// 4963 섬의 개수

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
using namespace std;
const int MAX = 51;
bool graph[MAX][MAX], visit[MAX][MAX];
int result = 0, num_land = 0, num_visit = 0, curr_x, curr_y;

void init_graph(int& row) {
	for (int i = 0; i < row; ++i) {
		memset(graph[i], 0, sizeof(bool) * MAX);
		memset(visit[i], 0, sizeof(bool) * MAX);
	}
	result = num_land = num_visit = 0;
}

void dfs(int& row, int& col, int x, int y) {
	// 지도 밖으로 나갔을 경우
	if (x < 0 || x > col || y < 0 || y > row) return;
	// 바다(0)이거나 || 이미 방문했거나
	if (!graph[y][x] || visit[y][x]) return;
	// land(1)의 개수와 방문한 노드의 개수가 같을 경우 ==> 모두 방문함
	if (num_land == num_visit) return;
	// 첫 방문 위치에서만 섬의 개수를 증가시켜준다.
	if (x == curr_x && y == curr_y) result++;

	visit[y][x] = true; num_visit++;
	/*  좌상  상  우상
		 좌  현재  우
		좌하  하  우하 */
	dfs(row, col, x - 1, y - 1); dfs(row, col, x, y - 1); dfs(row, col, x + 1, y - 1);
	dfs(row, col, x - 1, y); /* 현재 노드(x, y) */ dfs(row, col, x + 1, y);
	dfs(row, col, x - 1, y + 1); dfs(row, col, x, y + 1); dfs(row, col, x + 1, y + 1);
}

int main() {
	while (1) {
		int row, col; scanf("%d %d", &col, &row);
		if (!row && !col) break;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				scanf("%d", &graph[i][j]);
				if (graph[i][j]) num_land++;
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				curr_x = j, curr_y = i;
				dfs(row, col, j, i);
			}
		}
		printf("%d\n", result);
		init_graph(row);
	}

	return 0;
}
