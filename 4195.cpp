#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

/*
string을 두개 입력받아서 이미 존재하면 넘어가고,
존재하지 않는다면 order++ 값을 추가해서 넣어준다.
  - 존재 판단 : map(자동정렬)에 넣어서 find한다.
두 order 들의 hasSameParent 해서
서로 다른 parent를 가지고 있다면 unionParent를 해준다.
모든 parent 배열에서 방금 union 해준 parent를 가진 모든 요소의 개수를 출력한다.
*/

const int MAX = 2e5 + 10;
int cnt = 1, parent[MAX], s1_id, s2_id;
map<string, int> mp; // name, index

void init(int q) {
	cnt = 1; mp.clear();
	for (int i = 0; i <= q * 2; ++i) {
		parent[i] = i;
	}
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
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase; cin >> testcase;
	while (testcase--) {
		int query; cin >> query;
		init(query);
		while (query--) {
			string s1, s2; cin >> s1 >> s2;
			if (mp.find(s1) == mp.end()) { // 못찾았을경우
				mp.insert({ s1, cnt }); s1_id = cnt++; // 새로운 정점 삽입
			}
			else s1_id = mp.find(s1)->second; // 찾았다면 index만 반환받음
			if (mp.find(s2) == mp.end()) {
				mp.insert({ s2, cnt }); s2_id = cnt++;
			}
			else s2_id = mp.find(s2)->second;

			if (!hasSameParent(s1_id, s2_id)) { // 서로 다른 그래프에 속해있다면
				unionParent(s1_id, s2_id); // merge한다.
			}
			int res = 0, symbol = getParent(s1_id);
			for (int i = 1; i < cnt; ++i) { // 같은 그래프에 속해있는 정점 개수 완전탐색
				if (getParent(parent[i]) == symbol) res++;
			}
			cout << res << '\n'; // 출력
		}
	}

	return 0;
}

// 다른 사람들의 결과보다 시간 측면에서 좋지 못한 결과를 보여줬기 때문에,
// AC는 받았지만 더 개선된 소스코드를 작성하고 싶었다.
// 그 방법은->
// 나는 마지막에 결과값을 브루트포스로 일일이 탐색하여 출력했지만,
// unionParent 연산을 수행할 때 마다 그래프에 속해지는 요소의 개수를 미리 저장해두는 방식을 사용하면 훨씬 더 빠르다.

// 아래는 수정을 거친 소스코드이다.
