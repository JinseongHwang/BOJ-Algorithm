#include <iostream>
using namespace std;
#define VERTEX_MAX 1000
#define EDGE_MAX 500000
int vertex, edge, result;
int in[EDGE_MAX][2];
bool bin[VERTEX_MAX][VERTEX_MAX];
bool visit[VERTEX_MAX];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int currPos) {
	if (!visit[currPos]) visit[currPos] = true;
	for (int i = 1; i <= vertex; i++) {
		if (!visit[i] && bin[currPos][i]) dfs(i);
	}
}
int main() {
	init();
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> in[i][0] >> in[i][1];
		bin[in[i][0]][in[i][1]] = true;
		bin[in[i][1]][in[i][0]] = true;
	}
	for (int i = 1; i <= vertex; i++) {
		if (visit[i]) continue;
		else {
			result++;
			dfs(i);
		}
	}
	cout << result << "\n";
	return 0;
}


// 2020-07-07 추가
#include <iostream>
using namespace std;

#define MAX 1001
bool graph[MAX][MAX], visit[MAX], foundComponent;
int V, E, result;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void dfs(int curr) {
	if (visit[curr]) return;
	visit[curr] = true; foundComponent = true;
	for (int i = 1; i <= V; ++i) {
		if (graph[curr][i] && !visit[i]) dfs(i);
	}
}

int main() {
	init();
	cin >> V >> E;
	for (int a, b, i = 0; i < E; ++i) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	// 문제에서 정점의 번호가 1부터 주어져서 0은 무시
	for (int i = 1; i <= V; ++i) {
		foundComponent = false;
		dfs(i);
		if (foundComponent) result++;
	}
	cout << result << "\n";

	return 0;
}
