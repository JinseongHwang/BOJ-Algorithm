#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 5e5 + 5;
int N, M, parent[MAX];

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool hasSameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b ? true : false;
}

int main() {
	register int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i <= N; ++i) parent[i] = i;
	int a, b, result = 0;
	for (i = 1; i <= M; ++i) {
		scanf("%d %d", &a, &b);
		if (result) continue;
		else if (hasSameParent(a, b)) result = i;
		else unionParent(a, b);
	}
	printf("%d\n", result);

	return 0;
}
