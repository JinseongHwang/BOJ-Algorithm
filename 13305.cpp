#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int llt;
typedef struct Data {
	llt idx, cost;
	
	bool operator<(const Data& a) const {
		return this->cost < a.cost;
	}
} Data;

const int MAX = 1e5 + 5;
vector<Data> v;
int dist[MAX];
bool visited[MAX];

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) scanf("%d", dist + i);

	for (int inp, i = 0; i < N - 1; ++i) {
		scanf("%d", &inp);
		v.push_back({ i, inp });
	}
	int undef; scanf("%d", &undef);
	sort(v.begin(), v.end());

	llt result = 0, cnt = 0, sz = v.size();
	while (cnt < N - 1) {
		for (int i = 0; i < sz; ++i) {
			int idx = v[i].idx;
			if (!visited[idx]) {
				for (int j = idx; j < sz; ++j) {
					result += (v[i].cost * dist[j]);
					visited[j] = true;
					cnt++;
					if (visited[j + 1]) break;
				}
			}
		}
	}
	printf("%lld\n", result);

	return 0;
}
