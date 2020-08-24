#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

bool compare(const pii& a, const pii& b) {
	// 항상 같은 경우도 따져줘야 원하는 대로 정렬된다.|
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int a, b, i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back(pii(a, b));
	}
	sort(v.begin(), v.end(), compare);

	int result = 1, endTime = v[0].second;
	for (int i = 1; i < v.size(); ++i) {
		if (v[i].first >= endTime) {
			result++;
			endTime = v[i].second;
		}
	}
	cout << result << "\n";

	return 0;
}
