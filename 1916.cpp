// 1916

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int INF = 1e9;
const int V_MAX = 1e6 + 1;
int v, e, start, End;
vector<pair<int, int>> vp[V_MAX]; // 간선 정보
int dist[V_MAX]; // 최소 비용

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void dijkstra() {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < cost) continue;

		for (int i = 0; i < vp[curr].size(); i++) {
			int neighbor = vp[curr][i].first;
			int neighborDist = cost + vp[curr][i].second;

			if (dist[neighbor] > neighborDist) {
				dist[neighbor] = neighborDist;
				pq.push(make_pair(-neighborDist, neighbor));
			}
		}
	}
}
int main() {
	init();
	cin >> v >> e;
	fill(dist, dist + v + 1, INF);
	for (int i = 1; i <= e; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		vp[from].push_back(make_pair(to, cost));
	}
	cin >> start >> End;
	dijkstra();
	cout << dist[End] << "\n";
	return 0;
}


// 2020-08-14 추가
// 1916 최소비용 구하기

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1010, INF = 0x7fffffff;
int V, E, S, dest, dist[MAX];
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijkstra() {
	dist[S] = 0;
	pq.push(pii(0, S));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] < cost) continue;
		for (const auto& elem : graph[curr]) {
			int nxt = elem.first;
			int ncost = elem.second;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push(pii(dist[nxt], nxt));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	fill(dist, dist + V + 1, INF);
	for (int from, to, cost, i = 0; i < E; ++i) {
		cin >> from >> to >> cost;
		graph[from].push_back(pii(to, cost));
	}
	cin >> S >> dest;
	dijkstra();
	cout << dist[dest] << '\n';

	return 0;
}
