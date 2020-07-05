#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int v, e, result;
bool graph[MAX][MAX];
bool visit[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void bfs(int curr) {
	queue<int> q;
	q.push(curr);
	visit[curr] = true;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int i = 1; i <= v; ++i) {
			if (graph[f][i] && !visit[i]) {
				q.push(i);
				visit[i] = true;
				result++;
			}
		}
	}
}

int main() {
	init();
	cin >> v >> e;
	for (int a, b, i = 0; i < e; ++i) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	bfs(1);
	cout << result << "\n";

	return 0;
}
