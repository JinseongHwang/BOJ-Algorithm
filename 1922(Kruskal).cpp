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


// 2020-07-29 추가

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int nv, ne, result, cnt = 1;
int parent[MAX];

typedef struct {
	int start, end, weight;
} Edge;

vector<Edge> v;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	int ap = getParent(a);
	int bp = getParent(b);
	ap < bp ? parent[bp] = ap : parent[ap] = bp;
}

bool hasSameParent(int a, int b) {
	int ap = getParent(a);
	int bp = getParent(b);
	return (ap == bp) ? true : false;
}

bool compare(Edge& a, Edge& b) {
	return a.weight < b.weight;
}

void kruskal() {
	// 정점 연결하면서 cnt++
	// cnt == nv 되면 return 하고 result 출력
	for (int i = 0; i < v.size(); ++i) {
		if (!hasSameParent(v[i].start, v[i].end)) { // 사이클검사
			unionParent(v[i].start, v[i].end);
			result += v[i].weight; // 가중치 합
			cnt++;
		}
		if (nv == cnt) return;
	}
}

int main() {
	init();
	cin >> nv >> ne;
	for (int i = 0; i <= nv; ++i) parent[i] = i;
	for (int i = 0; i < ne; ++i) {
		int a, b, c; cin >> a >> b >> c;
		Edge inp = { a,b,c };
		v.push_back(inp);
	}
	sort(v.begin(), v.end(), compare);
	kruskal();
	cout << result << '\n';

	return 0;
}
