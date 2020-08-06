#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 10;
typedef long long int llt;
typedef struct { // 간선의 정보를 저장
	int begin, end, weight;
} Edge;

bool compare(Edge& a, Edge& b) { // 가중치 기준 정렬
	return a.weight < b.weight;
}

int V, E, parent[MAX], cnt;
vector<Edge> graph;
llt result;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int getParent(int a) { // 최고 조상을 반환
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]); // 메모이제이션
}

void unionParent(int a, int b) { // 두 그래프(또는 정점) 병합
	a = getParent(a);
	b = getParent(b);
	(a > b) ? parent[a] = b : parent[b] = a; // 작은 번호가 부모라는 규칙
}

bool hasSameParent(int a, int b) { // 같은 조상을 가지는지 판별
	a = getParent(a);
	b = getParent(b);
	return (a == b) ? true : false;
}

void kruskal() { 
	for (const auto& curr : graph) {
		// 서로 다른 조상을 가진다
		// 사이클이 발생하지 않는다
		if (!hasSameParent(curr.begin, curr.end)) {
			unionParent(curr.begin, curr.end); // 병합
			result += curr.weight; // 가중치 더해줌
			cnt++; // 연결된 간선의 개수
		}
		// 정점의 개수 - 1 == 간선의 개수 -> MST 완성된 상태
		if (V - 1 == cnt) return;
	}
}

int main() {
	init();
	cin >> V >> E;
	// 최초 상태에서 자기 자신이 부모이다
	for (int i = 0; i <= V; ++i) parent[i] = i;
	for (int a, b, c, i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		Edge e = { a,b,c };
		graph.push_back(e);
	}
	sort(graph.begin(), graph.end(), compare); // 정렬
	kruskal(); // 크루스칼 알고리즘 적용
	cout << result << '\n'; // 출력

	return 0;
}
