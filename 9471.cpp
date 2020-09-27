#include <cstdio>
using namespace std;
typedef long long int llt;

llt pisano_period(llt& M) {
	// 초기값 설정
	llt f[3] = { 0, 1, 1 };

	// k(M) < M^2 조건에 따라 반복
	for (llt i = 0; i < M * M; ++i) {
		f[2] = (f[0] + f[1]) % M;
		f[0] = f[1];
		f[1] = f[2];
		// 피사노 주기의 핵심: mod 값이 0과 1이 나오는 시점이 주기가 시작되는 시점
		if (f[0] == 0 && f[1] == 1) return i + 1;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		llt N, M; scanf("%lld %lld", &N, &M); printf("%lld ", N);
		printf("%lld\n", pisano_period(M));
	}

	return 0;
}
