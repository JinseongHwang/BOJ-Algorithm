#include <iostream>
#include <queue>
using namespace std;

// 처음에 배열의 크기를 1e5로 잡아서 애먹었다!
const int MAX = 2e5 + 1;
bool visit[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n, k, result = 1; cin >> n >> k;
	visit[n] = true;
	if (n == k) {
		cout << "0\n";
		return 0;
	}

	queue<int> q;
	if (n) {
		q.push(n - 1); q.push(n + 1); q.push(n * 2);
	}
	else q.push(n + 1);

	int sz = q.size();
	while (1) {
		if (!sz) {
			result++;
			sz = q.size() - 1;
		}
		else sz--;

		int curr = q.front();
		if (curr == k) break;
		q.pop();

		if (curr - 1 >= 0 && !visit[curr - 1]) {
			q.push(curr - 1); visit[curr - 1] = true;
		}
		if ((curr + 1 < MAX || curr == 0) && !visit[curr + 1]) {
			q.push(curr + 1); visit[curr + 1] = true;
			if (!curr) continue;
		}
		if ((curr * 2) < MAX && !visit[curr * 2]) {
			q.push(curr * 2); visit[curr * 2] = true;
		}

	}
	cout << result << "\n";

	return 0;
}
