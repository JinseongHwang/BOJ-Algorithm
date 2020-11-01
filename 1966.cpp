
// 큐 사용하는 문제

#include <bits/stdc++.h>
using namespace std;

int priority[10];
typedef struct Doc {
	int K, P;
} Doc;
queue<Doc> Q;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int inp, i = 0; i < n; ++i) {
			scanf("%d", &inp);
			Q.push({ i, inp });
			priority[inp]++;
		}
		int order = 1; 
		bool finished = false;
		for (int currPriority = 9; currPriority > 0 && !finished; --currPriority) {
			while (priority[currPriority] > 0 && !finished) {
				Doc f = Q.front();
				if (f.P == currPriority) {
					if (f.K == m) {
						printf("%d\n", order);
						finished = true;
					}
					else {
						Q.pop();
						order++;
						priority[currPriority]--;

					}
				}
				else {
					Q.push(f);
					Q.pop();
				}
			}
		}
		while (!Q.empty()) Q.pop();
		memset(priority, 0, sizeof(priority));
	}


	return 0;
}
