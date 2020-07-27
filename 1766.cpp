#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 32001;
int n, m, indegree[MAX];
// 가능하면 낮은 번호부터 출력해야하기 때문에 최소힙 사용
priority_queue<int, vector<int>, greater<int> > q;
vector<int> v[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void topologySort() {
	// 진입차수가 0인 정점 번호를 큐에 삽입
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		int curr = q.top();
		q.pop();
		// 큐에서 꺼낸 순서대로 출력
		cout << curr << ' ';
		// curr에서 도달하는 정점의 차수를 하나 제거
		for (int next : v[curr]) {
			indegree[next]--;
			// 또 진입차수가 0이 되면 큐에 삽입
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	while (m--) {
		int from, to; cin >> from >> to;
		v[from].push_back(to);
		indegree[to]++;
	}
	topologySort();

	return 0;
}
