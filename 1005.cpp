#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

const int MAX = 1010;
int N, K, dest, indegree[MAX], reqTime[MAX], dp[MAX];
vector<int> vout[MAX];
vector<int> vin[MAX];

void init() { // 다음 testcase를 위한 초기화 과정
	memset(indegree, 0, sizeof(indegree));
	memset(reqTime, 0, sizeof(reqTime));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < MAX; ++i) { // 벡터 배열의 초기화는 clear을 반복해줘야함
		vout[i].clear();
		vin[i].clear();
	}
}

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (!indegree[i]) {
			q.push(i);
			dp[i] = reqTime[i];
		}
	}
	// 이 문제의 핵심적인 부분 !!!
	// 앞으로 indegree가 0이 되는 정점을 A라고 할 때,
	// vin[A] 요소들의 dp값들중 최대값 + reqTime[A] 을 dp[A]에 삽입
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (const auto& nxt : vout[curr]) {
			indegree[nxt]--;
			if (!indegree[nxt]) {
				q.push(nxt);
				int maxTime = 0;
				for (const auto& a : vin[nxt]) {
					if (maxTime < dp[a]) maxTime = dp[a];
				}
				dp[nxt] = maxTime + reqTime[nxt]; // 소요시간 누적 저장
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase; cin >> testcase;
	while (testcase--) {
		init();
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) cin >> reqTime[i]; // 소요시간 저장
		for (int from, to, i = 1; i <= K; ++i) {
			cin >> from >> to;
			indegree[to]++; // 진입차수 증가
			vout[from].push_back(to);
			// from -> to : 정점 하나의 처리가 끝나면 다음 정점의 진입차수를 낮춰주기 위함
			vin[to].push_back(from);
			// to <- from : 다음 정점으로 향하는 정점들 중 최대 시간을 찾기 위함
		}
		cin >> dest; // 목표 정점
		topologicalSort(); // 위상 정렬 응용
		cout << dp[dest] << '\n';
		// 시간을 누적 저장했기 때문에 바로 dest의 시간을 출력하면 이전에 처리했던 작업들의 합이 출력됨
	}
	return 0;
}
