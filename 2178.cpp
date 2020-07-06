#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

#define MAX 101
bool maze[MAX][MAX];
int dist[MAX][MAX], n, m, currDist = 1;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void bfs() {
	queue<pii> q;
	q.push(pii(1, 1));
	dist[1][1] = currDist;

	while (!q.empty()) {
		pii curr = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int X = curr.first + dx[i];
			int Y = curr.second + dy[i];
			if (X < 1 || X > m || Y < 1 || Y > n) continue;
			if (!maze[Y][X] || dist[Y][X] != 0) continue;
			q.push(pii(X, Y));
			// queue에 여러개가 들어와도 dist는 1만 더해진 값을 계속 push해야함.
			// 떠올리기 까다로웠음
			dist[Y][X] = dist[curr.second][curr.first] + 1;
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (int j = 1; j <= m; ++j) maze[i][j] = (s[j - 1] == '0') ? false : true;
	}

	bfs();
	cout << dist[n][m] << "\n";

	return 0;
}
