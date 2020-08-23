#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> coordinate;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int x, y, i = 0; i < n; ++i) {
		cin >> x >> y;
		coordinate.push_back(pii(y, x));
	}
	sort(coordinate.begin(), coordinate.end());
	for (int i = 0; i < n; ++i) cout << coordinate[i].second << " " << coordinate[i].first << "\n";

	return 0;
}
