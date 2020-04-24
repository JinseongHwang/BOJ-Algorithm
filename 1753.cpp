// 1753
// 2차원 벡터를 활용해서 인접행렬을 구현함.
// 하지만 메모리초과, 또한 시간초과가 나올 것을 예상함.
// 왜냐하면 정점의 갯수가 최대 2만개이기 때문이다.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int INF = 1e9;

typedef pair<bool, int> pbi;
vector<vector<int>> graph;
vector<pbi> dist;

int V, E, start;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int ret_min_node() {
	/* 갱신되고있는 start 노드에서 갈 수 있는 가장 가까운 곳의 index number을 반환 */
	int max_w = INF, result = 0;
	for (int i = 0; i < V; i++)
		if (max_w >= dist[i].second && dist[i].second > 0 && !dist[i].first) {
			max_w = dist[i].second;
			result = i;
		}
	return result;
}
int main() {
  init();
	cin >> V >> E >> start; 

	for (int i = 0; i < V; i++) {
		vector<int> element;
		element.resize(V, INF);
		graph.push_back(element);
	} dist.resize(V);

	dist[start - 1].first = true;
	for (int i = 0; i < V; i++) graph[i][i] = 0;
	for (int i = 0; i < E; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		graph[from - 1][to - 1] = cost;
	}
	for (int i = 0; i < V; i++)
		dist[i].second = graph[start - 1][i];
	/* 입력 완료 */

	while (1) {
		int cnt = 0; // 탈출 조건
		for (int i = 0; i < V; i++) {
			if (dist[i].first) cnt++;
		} if (cnt == V) break;

		int renew = 0;
		int curr = start - 1;
		int next = ret_min_node();

		renew += dist[next].second; // 방문할곳의 가중치를 더해놓고
		dist[next].first = true; // 방문
		/* 경유해서 가는 것이 더 저렴할 경우 갱신해줌. */
		for (int i = 0; i < V; i++) {
			if (graph[next][i] != INF && graph[next][i] != 0) {
				if (renew + graph[next][i] < dist[i].second)
					dist[i].second = renew + graph[next][i];
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[i].second == INF) cout << "INF\n";
		else cout << dist[i].second << "\n";
	}
	return 0;
}


// 1753
// 다시보자
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int INF = 1e9;
const int V_MAX = 2e4 + 1;
int v, e, start;
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
	cin >> v >> e >> start;
	fill(dist, dist + v + 1, INF);
	for (int i = 1; i <= e; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		vp[from].push_back(make_pair(to, cost));
	}
	dijkstra();
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}
