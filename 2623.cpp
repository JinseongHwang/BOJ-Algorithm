// #2623 음악프로그램

/*  위상정렬의 조건: 유향그래프 && 사이클없음
	위상정렬을 실시하려면 시작점을 찾을 수 있어야 하는데, 사이클이 있으면 시작점을 찾을 수 없다.
	대체적으로 큐를 사용해서 해결을 하는데, 방법은 다음과 같다.
	1. 진입차수가 0인 정점을 큐에 삽입한다.
	2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거한다.
	3. 간선 제거 이후에 진입 차수가 0이 된 정점을 큐에 삽입한다.
	4. 큐가 빌 때까지 2~3번 과정을 반복한다. 모든 원소를 방문하기 전에 큐가 빈다면 사이클이
	존재하는 것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과이다. */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;
int indegree[MAX];
vector<int> graph[MAX];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void topology_sort(int& n) {
	vector<int> result;
	queue<int> Q;
	for (int i = 1; i <= n; ++i) {
		if (!indegree[i]) Q.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (Q.empty()) {
			cout << "0\n";
			return;
		}
		int curr = Q.front();
		Q.pop();
		result.push_back(curr);
		for (int j = 0; j < graph[curr].size(); ++j) {
			indegree[graph[curr][j]]--;
			if (!indegree[graph[curr][j]]) Q.push(graph[curr][j]);
		}
	}
	for (int i = 0; i < n; ++i) cout << result[i] << "\n";
}

int main() {
	init();
	int n, query; cin >> n >> query;
	vector<int> input;
	for (int num, i = 0; i < query; ++i) {
		while (cin >> num) {
			input.push_back(num);
			if (input[0] + 1 == input.size()) break;
		}
		for (int j = 1; j < input[0]; ++j) {
			graph[input[j]].push_back(input[j + 1]);
			indegree[input[j + 1]]++;
		}
		input.clear();
	}
	topology_sort(n);

	return 0;
}


// 2020-07-29 추가
// 음악프로그램

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;
int n, query, indegree[MAX];
vector<int> v[MAX], result;
queue<int> q;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void topologySort() {
	for (int i = 1; i <= n; ++i) {
		// 진입차수가 0인 정점을 queue에 push
		if (!indegree[i]) q.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (q.empty()) { // 사이클이 발생한 경우
			cout << "0\n";
			return;
		}
		// queue에서 하나씩 꺼내서 result에 삽입
		int curr = q.front();
		q.pop();
		result.push_back(curr);
		// 꺼낸 정점을 삭제하는 연산
		// 정점이 삭제됨에 따라 받는 정점들의 진입 차수 감소
		// 감소 후 진입차수가 0이 되는 정점을 다시 queue에 push
		for (auto a : v[curr]) {
			indegree[a]--;
			if (!indegree[a]) q.push(a);
		}
	}
	// 결과값 출력
	for (const auto& res : result) cout << res << '\n';
}

int main() {
	init();
	cin >> n >> query; // 가수의 수, 질의 수
	while (query--) {
		int tmp; cin >> tmp; // 순서 개수
		vector<int> inp; // 필요한 순서 값들을 저장
		for (int a, i = 0; i < tmp; ++i) {
			cin >> a; inp.push_back(a);
			if (i > 0) indegree[a]++; // 진입차수 setting
		}
		for (int i = inp.size() - 1; i > 0; --i) {
			v[inp[i - 1]].push_back(inp[i]); // 순서 정보 setting
		}
	}
	topologySort(); // 위상정렬 및 출력

	return 0;
}
