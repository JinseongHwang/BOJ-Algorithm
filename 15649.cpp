#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
bool visit[9];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		arr[depth] = i;
		dfs(depth + 1);
		visit[i] = false;
	}
}
int main() {
	init();
	cin >> n >> m;

	dfs(0);

	return 0;
}
