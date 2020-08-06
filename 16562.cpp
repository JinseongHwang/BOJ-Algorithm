// 다른 사람들의 AC받은 소스와 비교하니 메모리 사용량, 구동 시간 등에서 효율적이지 못한 면을 보였다.
// 메모리는 큰 차이 없었으나 시간복잡도 측면에서 차이가 꽤 있었으며, 정해와는 거리가 멀다고 판단한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e4 + 10;
int V, E, B, parent[MAX], cnt, sum;
bool connected[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	(a > b) ? parent[a] = b : parent[b] = a;
}

bool hasSameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return (a == b) ? true : false;
}

int main() {
	init();
	cin >> V >> E >> B;
	for (int c, i = 1; i <= V; ++i) {
		parent[i] = i;
		cin >> c;
		pq.push(pii(c, i));
	}
	
	for (int a, b, i = 0; i < E; ++i) {
		cin >> a >> b;
		if (!hasSameParent(a, b)) {
			unionParent(a, b);
		}
	}

	while (!pq.empty()) {
		pii curr = pq.top(); pq.pop();
		int ac = getParent(curr.second);
		if (!connected[ac]) {
			sum += curr.first;
			for (int i = 1; i <= V; ++i) {
				if (getParent(i) == ac) {
					connected[i] = true; cnt++;
				}
			}
		}
	}
	if (B >= sum) cout << sum << '\n';
	else cout << "Oh no\n";

	return 0;
}
