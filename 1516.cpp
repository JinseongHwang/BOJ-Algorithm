// 다시 풀만한 가치가 있는 문제
// 위상정렬 + 힙을 이용하는 데, 입력받고 힙에 push하는 과정이 인상깊음.
// 또한 시간을 어떤 자료구조를 사용해 정렬해야하는지 정하는데 고민을 꽤 많이 함.

// 1516 게임 개발
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
// time, index (수정3)
// time이 앞으로 와서 정렬 기준이 되어야한다... 이건 치명적인 실수

const int MAX = 501;
int n, indegree[MAX], time[MAX];
vector<int> v[MAX]; // 갈 수 있는 곳을 저장

priority_queue<pii, vector<pii>, greater<pii> > pq; // 오름차순 힙, 최소힙

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void topoSort() {
	for (int i = 1; i <= n; ++i) if (!indegree[i]) pq.push(pii(time[i], i));
	// for (int i = 1; i <= n; ++i) {
	while(!pq.empty()) { // (수정2) - 상관없더라
		int curr = pq.top().second; pq.pop();
		for (const auto& a : v[curr]) {
			indegree[a]--;
			if (!indegree[a]) {
				time[a] += time[curr];
				// (수정1)위아래 순서
				// 시간을 먼저 더해주고 push해야한다.
				pq.push(pii(time[a], a));
			}
		}
	}
}

int main() {
	init();
	cin >> n;
	for (int i = 1; i <= n; ++i) { // 정점 번호
		for (int inp, j = 0;; ++j) {
			cin >> inp;
			if (inp == -1) break;
			if (j == 0) {
				time[i] = inp; // 시간과 정점 번호 삽입
			}
			else {
				indegree[i]++;
				v[inp].push_back(i);
			}
		}
	}
	topoSort();
	for (int i = 1; i <= n; ++i) cout << time[i] << '\n';

	return 0;
}
