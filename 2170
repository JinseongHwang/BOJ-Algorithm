#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 1e6 + 1;
pair<int, int> line[MAX];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		line[i] = make_pair(a, b);
	} /*입력완료*/
	sort(line, line + n);

	int result = 0;
	int left = line[0].first;
	int right = line[0].second;
	for (int i = 1; i < n; i++) {
		if (line[i].first > right) {
			result += right - left;
			left = line[i].first;
			right = line[i].second;
		}
		else {
			right = max(right, line[i].second);
		}
	}
	result += right - left;
	cout << result << "\n";
	return 0;
}
