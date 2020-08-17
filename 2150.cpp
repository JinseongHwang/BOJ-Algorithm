#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 10;
int V, E, id, dfsn[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x) {
	// dfsn 에는 노드 방문 순서가 저장된다.
	// 즉, 1부터 저장되기 때문에 0일 경우 방문하지 않은 정점이라 생각할 수 있다.
	dfsn[x] = ++id;
	s.push(x); // stack에 자신을 push한다

	// 여러 정점들 중 번호가 가장 작은 정점이 조상이라고 약속하자.
	// 자신 또는 자식들의 dfsn중 가장 작은 값을 ancestor에 갱신
	int ancestor = dfsn[x];
	for (const auto& node : graph[x]) {
		// 아직 방문하지 않았을 경우
		if (!dfsn[node]) ancestor = min(ancestor, dfs(node));
		// 방문은 했지만 아직 결정된 것이 없는 이웃 정점
		else if (!finished[node]) ancestor = min(ancestor, dfsn[node]);
	}

	// 자신이 조상일 경우 SCC를 추출한다.
	if (ancestor == dfsn[x]) {
		vector<int> scc;
		while (1) {
			// stack에서 자신이 나올 때까지 pop하고
			int curr = s.top();
			s.pop();
			scc.push_back(curr); // 하나의 scc로 묶어준다
			finished[curr] = true; // 이미 추출완료된 정점
			if (curr == x) break; // 자신 발견
		}
		sort(scc.begin(), scc.end()); // 문제 조건에 따른 정렬
		SCC.push_back(scc); // 전체 SCC 벡터에 하나의 SCC를 삽입
	}

	return ancestor;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 입력
	cin >> V >> E;
	for (int from, to, i = 0; i < E; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	// DFS를 수행하며 SCC를 추출
	for (int i = 1; i <= V; ++i) {
		if (!dfsn[i]) dfs(i);
	}

	// 문제 요구조건에 맞게 출력하기 위해 정렬 후 출력
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (const auto& comp : SCC) {
		for (const auto& v : comp) {
			cout << v << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}
