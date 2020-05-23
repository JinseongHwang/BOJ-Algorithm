// #2252 줄세우기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 32001;
int indegree[MAX];
vector<int> graph[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void topology_sort(int& n) {
	vector<int> result;
	queue<int> Q;
	for (int i = 1; i <= n; ++i) {
		if (!indegree[i]) Q.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		int curr = Q.front();
		Q.pop();
		result.push_back(curr);
		for (int j = 0; j < graph[curr].size(); ++j) {
			indegree[graph[curr][j]]--;
			if (!indegree[graph[curr][j]]) Q.push(graph[curr][j]);
		}
	}
	for (int i = 0; i < n; ++i) cout << result[i] << " ";
}

int main() {
	init();
	int n, query; cin >> n >> query;
	for (int u, v, i = 0; i < query; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	topology_sort(n);

	return 0;
}
