#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

typedef long long int llt;
#define MOD(X) (X % llt(1e9 + 7))
priority_queue<llt, vector<llt>, greater<llt> > pq; // min heap

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			llt input; scanf("%lld", &input);
			pq.push(input);
		}
		llt cost = 1;
		while (pq.size() >= 2) {
			llt slime1 = pq.top(); pq.pop();
			llt slime2 = pq.top(); pq.pop();
			llt res = MOD(slime1) * MOD(slime2);
			pq.push(res);
			cost *= MOD(res);
			cost = MOD(cost);
		}
		printf("%lld\n", cost);
		while (!pq.empty()) pq.pop();
	}

	return 0;
}
