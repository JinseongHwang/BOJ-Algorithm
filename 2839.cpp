#include <cstdio>
#include <algorithm>
using namespace std;

// 5kg 가능한 만큼 뽑는데, 나머지가 3의 배수일 때까지
// 나머지를 3으로 뽑아보고, 안된다면 안되는 것

int main() {
	int N; scanf("%d", &N);
	
	int five_n = 0;
	for (int i = 0; i <= N / 5; ++i) {
		if ((N - (i * 5)) % 3 == 0) five_n = i;
	}
	
	N -= (five_n * 5);

	if (N % 3 != 0) printf("-1\n");
	else printf("%d\n", five_n + (N / 3));

	return 0;
}
