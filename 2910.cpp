#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct Data {
	int key;
	int frequency;
	int startIndex;

	bool operator<(const Data& d) const {
		if (this->frequency == d.frequency) {
			return this->startIndex > d.startIndex;
		}
		return this->frequency < d.frequency;
	}
};

int main() {

	int N, C; scanf("%d %d", &N, &C);

	unordered_map<int, Data> mp;

	for (int input, i = 0; i < N; i++) {
		scanf("%d", &input);
		if (mp.find(input) != mp.end()) {
			mp[input].frequency++;
		}
		else {
			mp[input].key = input;
			mp[input].frequency = 1;
			mp[input].startIndex = i;
		}
	}

	priority_queue<Data, vector<Data> > pq;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		pq.push((*iter).second);
	}

	while (!pq.empty()) {
		int freq = pq.top().frequency;
		int key = pq.top().key;
		for (int i = 0; i < freq; i++) {
			printf("%d ", key);
		}
		pq.pop();
	}

	return 0;
}
