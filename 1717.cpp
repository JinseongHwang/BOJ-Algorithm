#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 1;
int parent[MAX]; // index: 원소의 번호, value: 부모의 번호

int get_parent(int a);
void union_parent(int a, int b);
bool find_parent(int a, int b);
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; ++i) {
		parent[i] = i; // 최초 각 원소의 부모는 자신이다.
	}
	for (int i = 0; i < m; ++i) {
		int cmd, from, to; // 양방향 그래프이다
		scanf("%d %d %d", &cmd, &from, &to);
		if (cmd) { // 같은 집합에 포함되어 있는지 확인
			find_parent(from, to) ? printf("YES\n") : printf("NO\n");
		}
		else { // 두 원소를 연결
			union_parent(from, to);
		}
	}
	return 0;
}
int get_parent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = get_parent(parent[a]); // path compression
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

const int MAX = 1e6 + 1;
int n, m, parent[MAX];


void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int getParent(int c) { // 재귀 탐색, 같은 값 나올 때까지
	if (parent[c] == c) return c;
	return parent[c] = getParent(parent[c]);
}

void unionParent(int p, int c) {
	int pp = getParent(p);
	int cc = getParent(c);
	pp < cc ? parent[pp] = cc : parent[cc] = pp;
}

bool hasSameParent(int a, int b) {
	int ap = getParent(a);
	int bp = getParent(b);
	// a의 부모와 b의 부모가 같으면 true
	return (ap == bp) ? true : false;
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) parent[i] = i;

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a) { // check and print
			hasSameParent(b, c) ? cout << "YES\n" : cout << "NO\n";
		}
		else { // append graph
			b < c ? unionParent(b, c) : unionParent(c, b);
		}
	}

	return 0;
}
