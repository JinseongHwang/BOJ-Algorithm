/*
	이분 그래프란,
	하나의 간선에 연결된 두 정점을 2가지 서로 다른 색으로 칠할건데,
	위 규칙을 지키며 모든 정점을 색칠할 수 있다면 이분그래프이다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX = 20005;
int V, E, visited[MAX] = { 0, }; // visited[0] = 방문하지않음, [1] = 1번색으로 칠함, [2] = 2번색으로 칠함
vector<int> graph[MAX];
/*
	bool graph[MAX][MAX] = { 0, };

	처음에는 MAX * MAX 만큼의 배열을 선언했다.
	MAX가 20,000 이므로, 400,000,000칸의 배열을 선언하는 꼴이다.
	될 줄 알았는데 메모리 초과가 바로 나왔다.
	
	양방향 그래프에서 정점 V에 대한 최대 간선의 개수는 V * (V - 1) / 2 = 대략 200,000,000 이다.
	기존 메모리 사용량을 반으로 줄일 수 있다.
	문제에서 최대 간선의 개수가 200,000 이라고 주어졌기 때문에, 동적 배열에 그래프 정보를 저장하기로 했다.
*/

bool bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1; // 처음은 1로 칠하고 들어간다. 2로 칠해도 상관없다.

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); ++i) { 
			int nxt = graph[curr][i]; // nxt: 현재 정점에서 갈 수 있는 정점들
			// 다음 정점을 방문 확인하기 전에 색이 같은지 확인하자.
			// 시간초과를 AC 코드로 바꿔주는 핵심 1
			if (visited[curr] == visited[nxt]) return false; 
			if (visited[nxt] == 0) {
				if (visited[curr] == 1) visited[nxt] = 2;
				else if (visited[curr] == 2) visited[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return true;
}

bool isBipartite() {
	for (int i = 1; i <= V; ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			int& nxt = graph[i][j];
			if (i != j && visited[i] == visited[nxt]) return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	while (T--) {
		// 입력
		scanf("%d %d", &V, &E);
		for (int from, to, i = 0; i < E; ++i) {
			scanf("%d %d", &from, &to);
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		/*	- 색칠하는 과정
			예를 들어, 다음과 같은 입력이 주어졌을 때
			```	4 2
				1 2
				3 4		```
			만약 연결그래프가 아닌 상태로 주어진다고 하더라도, 한 쪽을 색칠해둔 상태로 나머지 쪽을 색칠해도 무방하다.
			한 쪽을 이미 색칠하는데 큰 이상이 발견되지 않았다면, 반대 쪽을 판단해서 큰 이상 없다면 넘어가고 생기면 NO를 출력하면 끝이다.
		*/
		// 시간초과를 AC 코드로 바꿔주는 핵심 2
		for (int start = 1; start <= V; ++start) {
			if (visited[start] == 0) bfs(start);
		}
		
		// 모든 간선에 대한 최종 확인 과정
		isBipartite() ? printf("YES\n") : printf("NO\n");

		// 초기화
		for (int i = 0; i <= V; ++i) graph[i].clear();
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
