
/**
* Ref. https://mathbang.net/101
* 1. 거리를 실수로 계산하면 오차가 발생함
* 2. 두 원의 위치 관계의 모든 경우를 고려해야 함
*/

#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
	int x, y;
};

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		Point A, B;
		int distA, distB;
		scanf("%d %d %d %d %d %d", &A.x, &A.y, &distA, &B.x, &B.y, &distB);

		int dist = pow(B.x - A.x, 2) + pow(B.y - A.y, 2);
		int sum = pow(distA + distB, 2);
		int diff = pow(distA - distB, 2);

		if (dist == 0) { // 두 터렛이 동일한 위치에 존재
			if (diff == 0) printf("-1\n"); // 동치
			else printf("0\n"); // 겹치는 부분 없음
		}
		// 두 원이 외접 || 내접
		else if (dist == sum || dist == diff) printf("1\n");
		// 두 원이 두 개의 교점을 가짐
		else if (diff < dist && dist < sum) printf("2\n");
		// 두 원이 떨어져있는 경우
		// 작은 원이 큰 원 안에 속해있고, 중심이 다른 경우
		else printf("0\n");
	}

	return 0;
}
