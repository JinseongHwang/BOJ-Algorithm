#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX = 1e6 + 5, MOD = 1e9;
int f[MAX] = { 0, 1, 0, };

int main() {
	int n; scanf("%d", &n);
	bool minus = n < 0 ? true : false;
	n = abs(n);
	if (n == 0) { printf("0\n0\n"); return 0; }
	for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
	minus && n % 2 == 0 ? printf("-1\n%d\n", f[n] % MOD) : printf("1\n%d\n", f[n] % MOD);

	return 0;
}
