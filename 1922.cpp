#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1001;
int parent[MAX], n, m, result = 0;

int get_parent(int);
void union_parent(int, int);
bool find_parent(int, int);
class Edge {
public:
	int distance; // 필드 생성
	pii node;

	Edge(int distance, int a, int b) { // 생성자
		this->distance = distance;
		this->node.first = a;
		this->node.second = b;
	}
	bool operator<(Edge& edge) { // 연산자 오버로딩
		return this->distance < edge.distance;
	}
};
int main() {
	vector<Edge> v;
	scanf("%d %d", &n, &m);
	for (int a, b, c, i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(Edge(c, a, b));
	}
  
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) parent[i] = i;
	for (int i = 0; i < v.size(); ++i) {
		if (!find_parent(v[i].node.first, v[i].node.second)) {
			result += v[i].distance;
			union_parent(v[i].node.first, v[i].node.second);
		}
	}
	printf("%d\n", result);

	return 0;
}
int get_parent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = get_parent(parent[a]);
}
void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	a < b ? parent[b] = a : parent[a] = b;
}
bool find_parent(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}
