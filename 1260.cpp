#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001
int v, e, s;
bool graph[MAX][MAX];
bool visit[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void dfs(int currNode) {
	for (int i = 1; i <= v; ++i) {
		if (graph[currNode][i] && !visit[i]) {
			visit[i] = true;
			cout << i << " ";
			dfs(i);
		}
	}
}

void bfs(int startNode) {
	queue<int> q;
	q.push(startNode);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		visit[curr] = true;
		cout << curr << " ";
		for (int i = 1; i <= v; ++i) {
			if (graph[curr][i] && !visit[i]) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main() {
	init();
	cin >> v >> e >> s;
	for (int from, to, i = 0; i < e; ++i) {
		cin >> from >> to;
		graph[from][to] = true;
		graph[to][from] = true;
	}

	cout << s << " ";
	visit[s] = true;
	dfs(s); cout << "\n";
	fill(visit, visit + MAX, false);
	bfs(s); cout << "\n";

	return 0;
}
