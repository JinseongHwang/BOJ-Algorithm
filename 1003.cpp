#include <cstdio>
using namespace std;

int main() {
	int T; scanf("%d", &T);

	int fibo[41] = { 0, 1, 0, }; // 피보나치 기본 규칙
	for (int i = 2; i <= 40; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2]; // 점화식 적용

	while (T--) {
		int n; scanf("%d", &n);
		// 규칙에 따라 출력
		if (n == 0) printf("1 0\n");
		else printf("%d %d\n", fibo[n - 1], fibo[n]);
	}

	return 0;
}
