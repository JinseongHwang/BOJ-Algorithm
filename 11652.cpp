#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef long long int llt;
const int MAX = 1e5 + 5;

struct Data {
	llt value;
	int cnt;
	bool operator<(const Data& nxt) const {
		if (this->cnt == nxt.cnt) return this->value < nxt.value;
		return this->cnt > nxt.cnt;
	}
};

unordered_map<llt, int> mp;
Data arr[MAX];

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		llt inp; scanf("%lld", &inp);
		mp[inp]++;
	}

	int idx = 0;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		arr[idx++] = { (*iter).first, (*iter).second };
	}

	sort(arr, arr + idx);
	
	printf("%lld\n", arr[0].value);

	return 0;
}
