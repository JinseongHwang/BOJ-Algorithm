#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int llt;
typedef struct {
	llt ability, idx;
} Data;

const llt MAX = 2e6; // 500,000 * 4

llt n, seg[MAX]; // 0으로 초기화 된 세그먼트 트리
vector<Data> vd;

bool compareAbility(const Data& a, const Data& b) {
	return a.ability < b.ability;
}

bool compareIndex(const Data& a, const Data& b) {
	return a.idx < b.idx;
}

llt query(llt node, llt start, llt end, llt L, llt R) {
	if (L <= start && end <= R) return seg[node];
	if (R < start || end < L) return 0;
	llt mid = (start + end) / 2;
	llt res1 = query(node * 2, start, mid, L, R);
	llt res2 = query(node * 2 + 1, mid + 1, end, L, R);
	return res1 + res2;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%lld", &n);

	// 흩어진 값들을 연속적인 값으로 좌표 압축
	for (llt i = 0; i < n; ++i) {
		llt inp; scanf("%lld", &inp);
		vd.push_back({ inp, i });
	}
	sort(vd.begin(), vd.end(), compareAbility);
	for (llt i = 0; i < n; ++i) vd[i].ability = i;
	sort(vd.begin(), vd.end(), compareIndex);

	// 세그먼트 트리로 연산
	const llt sz = pow(2, (llt)log2(n - 1) + 1);
	for (llt i = 0; i < n; ++i) {
		// 앞에서 부터 내 등수를 밝히면서, 세그먼트 트리 갱신을 해준다.
		// 구간 합은 나보다 실력이 좋은 사람들을 찾아서 합한다.
		// 만약 나보다 뒤에 실력 좋은 사람이 따라오고 있다면, 아직 트리 갱신되기 전이므로 포함되지 않는다.
		// 결과값: 내 앞에 나보다 실력 좋은 사람 수 + 1
		printf("%lld\n", query(1, 0, sz - 1, vd[i].ability, n - 1) + 1);
		for (llt node = vd[i].ability + sz; node > 0; node /= 2) 
			seg[node]++;
	}

	return 0;
}
