#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 26
int n, result, houses;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool findNewHouse;
bool graph[MAX][MAX];
bool visit[MAX][MAX];
vector<int> results;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return; // 그래프를 벗어난 경우
	if (!graph[x][y] || visit[x][y]) return; // 집이 없거나 이미 방문했을 경우
	
	visit[x][y] = true; findNewHouse = true; houses++;
	dfs(x + dx[0], y + dy[0]); // 상
	dfs(x + dx[1], y + dy[1]); // 하
	dfs(x + dx[2], y + dy[2]); // 좌
	dfs(x + dx[3], y + dy[3]); // 우
}

int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			graph[i][j] = s[j] == '0' ? false : true;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			findNewHouse = false;
			houses = 0;
			dfs(i, j);
			if (findNewHouse) result++;
			if (houses) results.push_back(houses);
		}
	}
	sort(results.begin(), results.end());

	cout << result << "\n";
	for (const auto& res : results) cout << res << "\n";

	return 0;
}
