// 세그먼트 트리

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1e9
int seg[1 << 21]; // 세그먼트트리 값을 저장할 배열
int N, M; // N: 주어질 정수의 갯수, M: 쿼리의 갯수

int ret_min(int node, int start, int end, int left, int right) { // arg:: 노드번호, 탐색중인 노드의 시작점, 끝점, 탐색목표범위,,
	if (left <= start && right >= end) return seg[node]; // 모두 확인하지 않아도 되는 부분은 상위 노드만 확인한다.
	if (left > end || right < start) return INF; // 탐색하는 범위를 벗어났을 경우 탐색할 필요가 없다고 판단 -> INF 반환
	int mid = (start + end) / 2; // 트리 구조를 반으로 쪼개기 편리하게 하기 위함
	int result = min(ret_min(node * 2, start, mid, left, right), ret_min(node * 2 + 1, mid + 1, end, left, right));
	return result; // 탐색하는 범위의 최소값을 반환
}
int main() {
	scanf("%d %d", &N, &M);
	int size = pow(2, (int)log2(N) + 1); // 실제로 값이 입력되기 시작하는 노드의 번호 and 입력된 값에 따른 리프노드의 최소 갯수
	fill(seg, seg + (size * 2), INF); // 최소값을 찾아야 하므로 모든 노드를 INF로 채워준다.
	for (int i = 0; i < N; ++i) scanf("%d", &seg[size + i]); // 리프노드의 값 입력
	for (int i = size - 1; i > 0; --i) seg[i] = min(seg[i * 2], seg[i * 2 + 1]); // 리프노드를 제외한 모든 노드에 값을 채워넣는다.
	/* 포화이진트리 구조 완성 */
	
	while (M--) { // 쿼리의 갯수만큼 반복
		int left, right; scanf("%d %d", &left, &right); // 우리가 탐색하고자 하는 범위
		printf("%d\n", ret_min(1, 1, size, left, right));
	}
	return 0;
}
