#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 51
bool graph[MAX][MAX], visit[MAX][MAX], needWorm;
int result;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void initGraph(int w, int h) {
	for (int i = 0; i < h; ++i) {
		memset(graph[i], false, sizeof(bool) * w);
		memset(visit[i], false, sizeof(bool) * w);
	}
	result = 0;
}

void dfs(int w, int h, int x, int y) {
	if (x < 0 || x >= w || y < 0 || y >= h) return; // 범위를 벗어나는 경우
	if (!graph[y][x] || visit[y][x]) return; // 배추가 없거나 방문했을 경우

	visit[y][x] = true; needWorm = true;
	dfs(w, h, x + dx[0], y + dy[0]); // 하
	dfs(w, h, x + dx[1], y + dy[1]); // 상
	dfs(w, h, x + dx[2], y + dy[2]); // 우
	dfs(w, h, x + dx[3], y + dy[3]); // 좌
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		int width, height, v; cin >> width >> height >> v;
		for (int a, b, i = 0; i < v; ++i) {
			cin >> a >> b;
			graph[b][a] = true;
		}
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				needWorm = false;
				dfs(width, height, j, i);
				if (needWorm) result++;
			}
		}
		cout << result << "\n";
		initGraph(width, height);
	}

	return 0;
}
