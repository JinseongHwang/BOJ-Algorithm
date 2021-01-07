#include <cstdio>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	int cnt2 = 0, cnt5 = 0;
	for (int i = 2; i <= N; i++) {
		int curr = i;
		int cntTmp = 0;
		while (curr % 2 == 0) {
			cntTmp++;
			curr /= 2;
		}
		cnt2 += cntTmp;
		
		cntTmp = 0;
		while (curr % 5 == 0) {
			cntTmp++;
			curr /= 5;
		}
		cnt5 += cntTmp;
	}
	printf("%d\n", cnt2 < cnt5 ? cnt2 : cnt5);

	return 0;
}
