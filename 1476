#pragma warning (disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int E, S, M, result = 0; scanf("%d %d %d", &E, &S, &M);
	while (1) {
		int tmp = min({ E, S, M });
		E -= tmp; S -= tmp; M -= tmp;
		result += tmp;
		if (E == 0 && S == 0 && M == 0) break;
		if (E == 0) E += 15;
		if (S == 0) S += 28;
		if (M == 0) M += 19;
	}
	printf("%d\n", result);
	return 0;
}
