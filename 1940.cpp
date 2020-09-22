#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 15005;
int N, M, arr[2], list[MAX], result;
bool isused[MAX];

void solve(int k) {
	if (k == 2) {
		if (arr[0] < arr[1] && arr[0] + arr[1] == M) result++;
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!isused[i]) {
			isused[i] = true;
			arr[k] = list[i];
			solve(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", list + i);
	sort(list, list + N);
	solve(0);
	printf("%d\n", result);

	return 0;
}
