// #2146 다리만들기
// 오후 4시 정각 시작

#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Pos {
	int row, col;
} Pos;

const int MAX = 105, MAX_HSQR = 5005;
const int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
int N, cnt_island, selected[2], result = 987654321;
bool graph[MAX][MAX], visited[MAX][MAX], isused[MAX_HSQR];
vector<Pos> island[MAX_HSQR];

__inline int calc_dist(const Pos& a, const Pos& b) {
	return abs(a.row - b.row) + abs(a.col - b.col) - 1;
}

void dfs_naming(const int& curr_row, const int& curr_col) {
	visited[curr_row][curr_col] = true;
	island[cnt_island].push_back({ curr_row, curr_col });
	for (int i = 0; i < 4; ++i) {
		int nxt_row = curr_row + dr[i], nxt_col = curr_col + dc[i];
		if (nxt_row < 0 || nxt_row >= N || nxt_col < 0 || nxt_col >= N) continue;
		if (!graph[nxt_row][nxt_col] || visited[nxt_row][nxt_col]) continue;
		dfs_naming(nxt_row, nxt_col);
	}
}

void verification(int island1, int island2) {
	for (const Pos& i1 : island[island1]) {
		for (const Pos& i2 : island[island2]) {
			result = min(result, calc_dist(i1, i2));
		}
	}
}

void combination(int idx, int k) {
	if (k == 2) {
		verification(selected[0], selected[1]);
		return;
	}

	for (int i = idx; i <= cnt_island; ++i) {
		if (!isused[i]) {
			selected[k] = i;
			isused[i] = true;
			combination(i + 1, k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int inp; scanf("%d", &inp);
			graph[i][j] = inp;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (graph[i][j] && !visited[i][j]) {
				cnt_island++;
				dfs_naming(i, j);
			}
		}
	}
	combination(1, 0);
	printf("%d\n", result);

	return 0;
}
