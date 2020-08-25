#include <cstdio>
using namespace std;

int main() {
	int curr_H, curr_M, curr_S; scanf("%d:%d:%d", &curr_H, &curr_M, &curr_S);
	int start_H, start_M, start_S; scanf("%d:%d:%d", &start_H, &start_M, &start_S);

	// 다음날 start 시간에 잡겠다는 뜻, 현재 시간으로부터 얼마나 남았는지?

	// 연산
	int H = start_H - curr_H, M = start_M - curr_M, S = start_S - curr_S;
	if (S < 0) { M--; S += 60; }
	if (M < 0) { H--; M += 60; }
	if (H < 0) H += 24;
	
	// 출력
	H < 10 ? printf("0%d:", H) : printf("%d:", H);
	M < 10 ? printf("0%d:", M) : printf("%d:", M);
	S < 10 ? printf("0%d\n", S) : printf("%d\n", S);

	return 0;
}
