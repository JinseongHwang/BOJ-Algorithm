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


// 2020-07-29 추가
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 32001;
int n, query, indegree[MAX];
vector<int> v[MAX];
queue<int> q;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void topologySort() {
	for (int i = 1; i <= n; ++i) if (!indegree[i]) q.push(i);
	for (int i = 1; i <= n; ++i) {
		int curr = q.front();
		q.pop();
		cout << curr << ' ';
		for (const auto& a : v[curr]) {
			indegree[a]--;
			if (!indegree[a]) q.push(a);
		}
	}
}

int main() {
	init();
	cin >> n >> query;
	while (query--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	topologySort();

	return 0;
}
