#include <cstdio>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	int arr[105] = { 0, }, result = 0;
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	while (1) {
		int cnt = 0;
		for (int i = 1; i < N; ++i) {
			if (arr[i - 1] < arr[i]) cnt++;
		}
		if (cnt == N - 1) break;

		for (int i = 1; i < N; ++i) {
			while (arr[i - 1] >= arr[i]) {
				arr[i - 1]--;
				result++;
			}
		}
	}
	
	printf("%d\n", result);

	return 0;
}
