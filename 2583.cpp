#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101
int n, m, k, area, dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
bool graph[MAX][MAX], visit[MAX][MAX];
vector<int> result;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

// graph가 0인 각 영역의 크기를 반환한다.
void dfs(int r, int c) {
	if (visit[r][c]) return;
	visit[r][c] = true;
	area++;
	for (int i = 0; i < 4; ++i) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (visit[nr][nc] || graph[nr][nc]) continue;
		dfs(nr, nc);
	}
}

int main() {
	init();
	cin >> n >> m >> k;
	for (int a, b, c, d, i = 0; i < k; ++i) {
		cin >> a >> b >> c >> d;
		// 주어진 도형들을 2차원 배열에 맞게 상하반전시킴
		// [b][a] ~ [d - 1][c - 1]
		for (int j = b; j <= d - 1; ++j) {
			for (int k = a; k <= c - 1; ++k) graph[j][k] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!graph[i][j]) {
				dfs(i, j);
				if (area > 0) result.push_back(area);
				area = 0;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (const auto& res : result) cout << res << " ";

	return 0;
}
