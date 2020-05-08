// <bits/stdc++.h> 사용 경험.
// 소인수분해가 쓰이는 경우가 많으니 기억해두자.

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main() {
	int n; scanf("%d", &n);
	while (n != 1) {
		for (int i = 2; i <= n; ++i) {
			if (n % i == 0) {
				printf("%d\n", i);
				n /= i;
				break;
			}
		}
	}
	return 0;
}
