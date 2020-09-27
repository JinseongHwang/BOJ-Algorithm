#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct Pos {
	int row, col;
	bool isused;
	
	bool operator<(const Pos& nxt) const {
		if (this->row == nxt.row) return this->col < nxt.col;
		else return this->row < nxt.row;
	}
} Pos;

const int MAX = 51, INF = 0x7fffffff;
int N, M; // 도시의 크기(N*N), 남겨둘 치킨 가게의 개수
int result = INF;
vector<Pos> hmlist, cklist;

__inline int calc_dist(const Pos& a, const Pos& b) {
	return abs(a.row - b.row) + abs(a.col - b.col);
}

int total_dist(vector<Pos>& list) {
	int res = 0;
	for (int i = 0; i < hmlist.size(); ++i) {
		int nth_ck_dist = INF;
		for (int j = 0; j < M; ++j) {
			nth_ck_dist = min(nth_ck_dist, calc_dist(hmlist[i], list[j]));
		}
		res += nth_ck_dist;
	}
	return res;
}

void combination(vector<Pos>& list, int idx, int k) {
	if (k == M) {
		for (int i = 1; i < M; ++i) if (list[i] < list[i - 1]) return;
		result = min(result, total_dist(list));
		return;
	}

	for (int i = idx; i < cklist.size(); ++i) {
		Pos& curr = cklist[i];
		if (!curr.isused) {
			list[k] = curr;
			curr.isused = true;
			combination(list, i + 1, k + 1);
			curr.isused = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int inp; scanf("%d", &inp);
			if (inp == 1) hmlist.push_back({ i,j,false });
			else if (inp == 2) cklist.push_back({ i,j,false });
		}
	}
	sort(cklist.begin(), cklist.end());
	vector<Pos> list(M);
	combination(list, 0, 0);
	printf("%d\n", result);

	return 0;
}
