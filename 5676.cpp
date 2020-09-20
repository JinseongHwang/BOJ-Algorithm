#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 4e5 + 10; // MAX * 4
int N, K, seg[MAX];

// 부호 결정 함수 오버로딩
int sign(int x) {
	if (x == 0) return 0;
	else if (x < 0) return -1;
	else return 1;
}

int sign(int x, int y) { // multiplication result
	int result = x * y;
	if (result == 0) return 0;
	else if (result < 0) return -1;
	else return 1;
}

void print(int x) {
	if (x == 0) printf("0");
	else if (x < 0) printf("-");
	else printf("+");
}

int query(int node, int start, int end, int L, int R) {
	if (L <= start && end <= R) return seg[node];
	if (end < L || R < start) return 1;
	int mid = (start + end) / 2;
	int res1 = query(node * 2, start, mid, L, R);
	int res2 = query(node * 2 + 1, mid + 1, end, L, R);
	return sign(res1, res2);
}

int main() {
	//freopen("input.txt", "r", stdin);

	while (scanf("%d %d", &N, &K) != EOF) {
		// segment tree 시작 위치: sz
		const int sz = pow(2, (int)(log2(N - 1) + 1));
		// 양수(1)로 초기화 -> 뭘 곱해도 결과값이 변하지 않음
		fill(seg, seg + (sz * 2) + 1, 1);
		// 배열 입력받음
		for (int i = sz; i < sz + N; ++i) scanf("%d", &seg[i]);
		// segment tree 완성
		for (int i = sz - 1; i > 0; --i) seg[i] = sign(sign(seg[i * 2], seg[i * 2 + 1]));
		// query 연산 수행
		while (K--) {
			char c; int a, b;
			scanf(" %c %d %d", &c, &a, &b);
			if (c == 'C') { // 변경
				// 부호 같으면 업데이트 쿼리 수행하지 않는다.
				int node = sz + a - 1;
				if (sign(seg[node]) != sign(b)) {
					seg[node] = b;
					for (int i = node / 2; i > 0; i /= 2) seg[i] = sign(sign(seg[i * 2], seg[i * 2 + 1]));
				}
			}
			else { // 곱셈
				print(query(1, 1, sz, a, b));
			}
		}
		printf("\n");
	}

	return 0;
}
