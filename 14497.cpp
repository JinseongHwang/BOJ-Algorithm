#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 305;

typedef struct {
	int row, col;
} Pos;

int n, m, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
Pos src, dest;
char room[MAX][MAX];
bool visited[MAX][MAX];

int bfs() {
	int result = 0;
	queue<Pos> q;

	while (room[dest.row][dest.col] != '0') {
		result++;
		if (q.empty()) q.push(src);
		memset(visited, false, sizeof(visited));
		visited[src.row][src.col] = true;
		while (!q.empty()) {
			int curr_row = q.front().row, curr_col = q.front().col;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int next_row = curr_row + dx[i], next_col = curr_col + dy[i];
				if (next_row <= 0 || next_row > n || next_col <= 0 || next_col > m) continue;
				if (visited[next_row][next_col]) continue;
				if (room[next_row][next_col] == '1' || room[next_row][next_col] == '#') {
					visited[next_row][next_col] = true;
					room[next_row][next_col] = '0';
				}
				else { // room[next_row][next_col] == '0'
					visited[next_row][next_col] = true;
					q.push({ next_row, next_col });
				}
			}
		}
	}

	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &src.row, &src.col, &dest.row, &dest.col);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf(" %c", &room[i][j]);
	// 입력완료
	printf("%d\n", bfs());
	return 0;
}
