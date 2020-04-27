// 순환함수로 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int combination(int n, int k) {
	if ((n == k) || (k == 0)) return 1;
	return combination(n - 1, k - 1) + combination(n - 1, k);
}
int main() {
	int n, k; scanf("%d %d", &n, &k);
	printf("%d\n", combination(n, k));
	return 0;
}
