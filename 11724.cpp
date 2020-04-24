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
