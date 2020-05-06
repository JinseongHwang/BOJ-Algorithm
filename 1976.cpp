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
