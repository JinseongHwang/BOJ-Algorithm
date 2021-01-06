#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long int llt;
llt GCD(llt a, llt b) { return b == 0 ? a : GCD(b, a % b); }

int main() {
	llt A, B; scanf("%lld %lld", &A, &B);
	llt len = GCD(A, B);
	for (llt i = 0; i < len; i++) printf("1");

	return 0;
}
