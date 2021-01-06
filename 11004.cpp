#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 5e6 + 5;
int arr[MAX];

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);
	sort(arr, arr + N);
	printf("%d\n", arr[K - 1]);
	return 0;
}
