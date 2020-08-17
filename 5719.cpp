#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 510, INF = 987654321;
int V, E, src, dest, dist[MAX];
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq; // 최소힙

vector<int> allPath[MAX]; // 모든 최단경로를 저장
bool isRemoved;

void init() { // 다음 testcase를 위한 초기화
	fill(dist, dist + V + 1, INF);
	for (int i = 0; i <= V; ++i) {
		graph[i].clear(); allPath[i].clear();
	}
	while (!pq.empty()) pq.pop();
	isRemoved = false;
}

void dijkstra() {
	dist[src] = 0;
	pq.push(pii(0, src));

	while (!pq.empty()) {
		int cost = pq.top().first, curr = pq.top().second;
		pq.pop();
		// 현재 추출한 거리가 기존의 거리보다 클 경우 갱신 가능성이 없다
		if (dist[curr] < cost) continue;
		for (const auto& elem : graph[curr]) {
			int nxt = elem.first, d = elem.second;
			if (dist[nxt] > cost + d) {
				dist[nxt] = cost + d;
				pq.push(pii(dist[nxt], nxt));

				// 이 문제의 핵심 !
				// 갱신됐다면 이전의 데이터를 비워주고,
				// 최단 경로의 정점을 삽입한다.
				if (!isRemoved) { 
					allPath[nxt].clear();
					allPath[nxt].push_back(curr);
				}
			}
			// 기존에 저장된 최단경로와 같은 거리가 발견됐다면
			// 최단 경로가 여러개일 경우이다.
			else if (!isRemoved && dist[nxt] == cost + d)
				allPath[nxt].push_back(curr);
		}
	}
}

// Almost Single Source Shortest Path
// BFS로 dest에서 src로 찾아가며
// 최단 경로에 속한 간선의 가중치를 INF값으로 변경한다.
void removeASSP() { 
	queue<int> q;
	q.push(dest);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (const auto& a : allPath[curr]) {
			for (auto& b : graph[a]) {
				if (curr == b.first) b.second = INF;
			}
			q.push(a);
		}
	}

	isRemoved = true;
	fill(dist, dist + V + 1, INF); // 다음 dijkstra를 위해 dist 초기화
	dijkstra(); // 거의 최단 경로를 찾기 위해 dijkstra 실행
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> V >> E; 
		if (V == 0 && E == 0) break;
		init();
		cin >> src >> dest; // source, destination
		for (int from, to, cost, i = 0; i < E; ++i) {
			cin >> from >> to >> cost;
			graph[from].push_back(pii(to, cost));
		}
		dijkstra(); // 최단경로 찾기
		removeASSP(); // 최단경로 삭제 및 거의 최단경로 찾기
		(dist[dest] >= INF) ? (cout << "-1\n") : (cout << dist[dest] << '\n');
	}

	return 0;
}
