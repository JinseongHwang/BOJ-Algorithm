#include <cstdio>
#include <deque>
#include <vector>
#include <unordered_set>
using namespace std;

const int K_MAX = 3005;
//const int MAX = 3e6 + K_MAX + 10; // N_MAX + K_MAX + freely 10
const int MAX = 3e4 + K_MAX + 10;
int N, d, k, c, sushi[MAX], isContained[K_MAX];
deque<int> dq;
unordered_set<int> notUnique;

__inline void rm(int x) {
	auto res = notUnique.find(x);
	if (res != notUnique.end()) notUnique.erase(res);
}

__inline void ins(int x) {
	auto res = notUnique.find(x);
	if (res == notUnique.end()) notUnique.insert(x);
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; ++i) scanf("%d", sushi + i);
	for (int i = N; i < N + k - 1; ++i) sushi[i] = sushi[i - N]; // 원형을 선형으로 표현

	const int sz = N + k - 1; // 총 배열의 크기
	for (int i = 0; i < k; ++i) {
		int curr = sushi[i];
		dq.push_back(curr);
		isContained[curr]++;
		if (isContained[curr] > 1) notUnique.insert(curr);
	}

	int L = 0, R = k - 1, result = 0;
	while (R < sz) {
		int res = k;
		for (auto iter = notUnique.begin(); iter != notUnique.end(); ++iter) {
			res -= (isContained[*iter] - 1);
		}
		if (!isContained[c]) res++;
		if (result < res) result = res;

		// dq의 이동
		int f = dq.front();
		isContained[f]--;
		if (isContained[f] <= 1) rm(f);
		dq.pop_front();
		L++; R++;
		dq.push_back(sushi[R]);
		int b = sushi[R];
		isContained[b]++;
		if (isContained[b] > 1) ins(b);
	}
	printf("%d\n", result);

	return 0;
}
