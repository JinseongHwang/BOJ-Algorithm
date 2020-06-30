#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	vector<pii> vp;
	int level[51]; fill(level, level + 51, 1);
	int n; cin >> n;
	for (int a, b, i = 0; i < n; ++i) {
		cin >> a >> b;
		vp.push_back(pii(a, b));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (vp[i].first > vp[j].first&& vp[i].second > vp[j].second) level[j]++;
		}
	}
	for (int i = 0; i < n; ++i) cout << level[i] << " ";
	cout << "\n";

	return 0;
}
