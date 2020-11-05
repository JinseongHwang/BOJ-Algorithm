
// 백트래킹으로 해결

#include <bits/stdc++.h>
using namespace std;

int result;
void solve(int n, int sum) {
	if (n == sum) {
		result++;
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		sum += i;
		if(sum <= n) solve(n, sum);
		sum -= i;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		if (n == 1) {
			// 1
			result = 1;
		}
		else if (n == 2) {
			// 1+1, 2
			result = 2;
		}
		else if (n == 3) {
			// 1+1+1, 1+2, 2+1, 3
			result = 4;
		}
		else {
			solve(n, 0);
		}
		printf("%d\n", result);
		result = 0;
	}

	return 0;
}
