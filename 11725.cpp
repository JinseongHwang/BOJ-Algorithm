#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int N, parent[MAX];
vector<bool> visited(MAX);
vector<int> graph[MAX];

void DFS(int curr) {
	for (int& nxt : graph[curr]) {
		if (visited[nxt]) continue;
		visited[nxt] = true;
		parent[nxt] = curr;
		DFS(nxt);
	}
}

int main() {
	scanf("%d", &N);

	for (int a, b, i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	visited[1] = true; 
	DFS(1);
	for (int i = 2; i <= N; i++) printf("%d\n", parent[i]);
	
	return 0;
}
