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
