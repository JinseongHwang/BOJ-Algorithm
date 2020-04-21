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
