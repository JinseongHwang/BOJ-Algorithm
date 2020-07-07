#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

#define MAX 1001
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int graph[MAX][MAX], n, m, result, fresh, ripen;
bool visit[MAX][MAX];
queue<pii> q;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void bfs() {
	int sz = q.size();
	while (!q.empty()) {
		// 날짜 계산용 -> 하루에 얼마나 변화가 이루어 지는지 ~
		if (sz == 0) {
			result++;
			// 넣고나서 하루를 시작하기 때문에 1을 빼고 넣어준다.
			sz = q.size() - 1;
		}
		else sz--;
		
		pii curr = q.front();
		q.pop();
		visit[curr.first][curr.second] = true;
		for (int i = 0; i < 4; ++i) {
			int nr = curr.first + dy[i];
			int nc = curr.second + dx[i];
			if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
			// graph[nr][nc] 가 1이거나 -1이면 이미 익었거나 없는 칸이므로 못간다.
			if (visit[nr][nc] || abs(graph[nr][nc]) == 1) continue;
			q.push(pii(nr, nc));
			graph[nr][nc] = 1; ripen++;
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) fresh++; // 익지않은 토마토의 개수 저장
			if (graph[i][j] == 1) { // 이미 익은 토마토의 위치 저장
				q.push(pii(i, j));
				visit[i][j] = true;
			}
		}
	}
	// 익지 않은 토마토가 없다면?
	if (!fresh) {
		cout << "0\n";
		return 0;
	}
	bfs();
	// 처음에 익지 않은 토마토의 개수와 시간이 흘러 익게된 토마토의 개수가 같다면
	// 모든 토마토가 익게된 것이다.
	if (fresh == ripen) cout << result << "\n";
	else cout << "-1\n";
		
	return 0;
}
