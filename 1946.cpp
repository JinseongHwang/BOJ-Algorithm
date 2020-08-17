#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		vector<pii> vp;
		for (int a, b, i = 0; i < n; ++i) {
			cin >> a >> b;
			vp.push_back(pii(a, b));
		}
		sort(vp.begin(), vp.end());
		// 1차 순위로 정렬 후 2차 순위가 최소값일 경우
		// 선발되지 못한다.
		for (int i = 1; i < vp.size(); ++i) {
			if (vp[i - 1].second < vp[i].second) {
				vp[i].second = vp[i - 1].second;
				n--;
			}
		}
		cout << n << '\n';
		vp.clear();
	}
	return 0;
}
