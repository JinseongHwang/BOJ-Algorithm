#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
typedef struct {
	int start, end, weight;
} Edge;

bool compare(Edge& a, Edge& b) {
	return a.weight < b.weight;
}

int V, E, parent[MAX];
vector<Edge> graph;

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	(a > b) ? parent[a] = b : parent[b] = a;
}

bool hasSameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return (a == b) ? true : false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i <= V; ++i) parent[i] = i;

	for (int a, b, c, i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		Edge e = { a,b,c };
		graph.push_back(e);
	}
	sort(graph.begin(), graph.end(), compare);

	int unionCnt = 0, result = 0;
	for (const auto& curr : graph) {
		if (!hasSameParent(curr.start, curr.end)) {
			unionParent(curr.start, curr.end);
			result += curr.weight;
			unionCnt++;
		}
		if (V - 2 == unionCnt) { // 핵심
			// 두 도시로 분할해야 한다.
			// 따라서 MST 형태에서 최대 비용 간선 하나를 뺀다.
			cout << result << '\n';
			break;
		}
	}

	return 0;
}
