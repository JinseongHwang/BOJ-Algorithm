#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

#define MAX 301
int dist[MAX][MAX];
bool visit[MAX][MAX];
// dx: column move, dy: row move
int sz, dx[8] = { 1,2,2,1,-1,-2,-2,-1 }, dy[8] = { -2,-1,1,2,2,1,-1,-2 };
pii s, e;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void bfs() {
	queue<pii> q;
	q.push(s);
	dist[s.first][s.second] = 0;
	visit[s.first][s.second] = true;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		visit[curr.first][curr.second] = true;
		for (int i = 0; i < 8; ++i) {
			int nr = curr.first + dx[i];
			int nc = curr.second + dy[i];
			if (nr < 0 || nr >= sz || nc < 0 || nc >= sz) continue;
			if (dist[nr][nc] != 0 || visit[nr][nc]) continue;
			q.push(pii(nr, nc));
			dist[nr][nc] = dist[curr.first][curr.second] + 1;
		}
	}
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		cin >> sz;
		cin >> s.first >> s.second;
		cin >> e.first >> e.second;
		bfs();

		cout << dist[e.first][e.second] << "\n";
		for (int i = 0; i < sz; ++i) {
			memset(dist[i], 0, sizeof(int) * sz);
			memset(visit[i], 0, sizeof(bool) * sz);
		}
	}

	return 0;
}
