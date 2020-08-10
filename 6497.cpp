// MST의 최소 비용을 출력하는 문제가 아닌,
// 최대 비용 - 최소 비용, 즉 절약하는 비용의 최대값을 출력하는 문제.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2e5 + 10;
typedef struct {
	int start, end, weight;
} Edge;

bool compare(Edge& a, Edge& b) {
	return a.weight < b.weight;
}

int V, E, parent[MAX], maxWeight;
vector<Edge> graph;

void init(int V) {
	for (int i = 0; i <= V; ++i) parent[i] = i;
	maxWeight = 0;
	graph.clear();
}

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

	while (1) {
		cin >> V >> E;
		if (V == 0 && E == 0) break;
		init(V);

		for (int a, b, c, i = 0; i < E; ++i) {
			cin >> a >> b >> c;
			maxWeight += c;
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
			if (V - 1 == unionCnt) {
				cout << maxWeight - result << '\n';
				break;
			}
		}
	}

	return 0;
}
