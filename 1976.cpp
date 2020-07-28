#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 201;
int parent[MAX]; // index: 원소의 번호, value: 부모의 번호

int get_parent(int a);
void union_parent(int a, int b);
bool find_parent(int a, int b);
int main() {
	int V, C; scanf("%d %d", &V, &C); // vertex, city

	// 최초 경우 각 원소의 부모는 자신이다.
	for (int i = 0; i <= V; ++i) parent[i] = i;

	for (int i = 1; i <= V; ++i) {
		for (int value, j = 1; j <= V; ++j) {
			scanf("%d", &value);
			if (value) union_parent(i, j);
		}
	}
	
	bool isSame = true;
	int tmp; scanf("%d", &tmp);
	int first_route_parent = get_parent(tmp);
	for (int nth_route_parent, i = 0; i < C - 1; ++i) {
		scanf("%d", &nth_route_parent);
		if (first_route_parent != get_parent(nth_route_parent)) {
			isSame = false; break;
		}
	}

	if (isSame) printf("YES\n");
	else printf("NO\n");

	return 0;
}
int get_parent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = get_parent(parent[a]);
}
void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	a < b ? parent[b] = a : parent[a] = b;
}
bool find_parent(int a, int b) {
	// 두 원소의 부모가 같다면 true, 아니면 false
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}


// 2020-07-28 추가
#include <iostream>
using namespace std;

const int MAX = 1001;
int n, m, parent[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 자기 자신이 부모로 초기화
	for (int i = 0; i < MAX; ++i) parent[i] = i;
}

int getParent(int c) { // 조상 부모를 반환
	if (parent[c] == c) return c;
	return parent[c] = getParent(parent[c]);
}

void unionParent(int a, int b) { // 두 그래프를 합한다
	int ap = getParent(a);
	int bp = getParent(b);
	ap < bp ? parent[bp] = ap : parent[ap] = bp;
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int inp; cin >> inp;
			// 양방향으로 주어지기 때문에 필요없는 한쪽은 버린다
			if (j < i) continue;
			if (inp) unionParent(i, j); // 합
		}
	}
	int tmp; cin >> tmp;
	int symbol = getParent(tmp); // 최초 부모랑
	for (int i = 0; i < m - 1; ++i) {
		cin >> tmp;
		if (symbol != getParent(tmp)) { // 다른 노드 부모랑 다르면 NO 하고 끝냄
			cout << "NO\n"; return 0;
		}
	}
	cout << "YES\n"; // 안끝났다면 YES

	return 0;
}
