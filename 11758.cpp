#include <cstdio>
using namespace std;

typedef struct Point {
	int x, y;
} Point;

__inline int CrossProduct(const Point& a, const Point& b) {
	return (a.x * b.y) - (b.x * a.y);
}

int main() {
	Point p[3];
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	// 두 개의 벡터 생성
	Point v1 = { p[1].x - p[0].x, p[1].y - p[0].y };
	Point v2 = { p[2].x - p[0].x, p[2].y - p[0].y };
	// 외적 결과
	int res = CrossProduct(v1, v2);
	if (res > 0) printf("1\n"); // ccw
	else if (res < 0) printf("-1\n"); // cw
	else printf("0\n"); // parallel

	return 0;
}
