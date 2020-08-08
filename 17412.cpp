// 17412 도시 왕복하기 1
// 네트워크 플로우(최대 유량)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 401, INF = 987654321;
int N, P, result;
int capacity[MAX][MAX]; // 용량
int flow[MAX][MAX]; // 유량
vector<int> adj[MAX]; // 인접리스트

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> P;
	for (int u, v, i = 0; i < P; ++i) {
		cin >> u >> v;
		capacity[u][v] = 1; // 용량을 1로 초기화
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int S = 1, E = 2;
	while (1) {
		int prev[MAX]; fill(prev, prev + N + 1, -1); // -1로 초기화
		queue<int> q;
		q.push(S); // 시작점 push
		while (!q.empty() && prev[E] == -1) {
			int curr = q.front();
			q.pop();
			for (int next : adj[curr]) { // curr에서 갈 수 있는 간선
				if (capacity[curr][next] > flow[curr][next] && prev[next] == -1) {
					prev[next] = curr; // A
					q.push(next);
					if (next == E) break;
				}
			}
		}
		// A지점에서 갱신이 안됐다면 E로 못간다는 의미
		if (prev[E] == -1) break;

		int MF = INF; // minimum flow
		for (int i = E; i != S; i = prev[i])
			// S는 1로 고정되어있음
			MF = min(MF, capacity[prev[i]][i] - flow[prev[i]][i]);

		for (int i = E; i != S; i = prev[i]) {
			// 순방향 간선, 역방향 간선 연산
			flow[prev[i]][i] += MF;
			flow[i][prev[i]] -= MF;
		}
		result += MF;
	}
	cout << result << '\n';

	return 0;
}
