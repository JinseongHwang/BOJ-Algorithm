// 이진 탐색 STL 사용

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		vector<int> v;
		int n, q; cin >> n;
		for (int inp, i = 0; i < n; ++i) { cin >> inp; v.push_back(inp); }
		sort(v.begin(), v.end());
		cin >> q;
		for (int inp, i = 0; i < q; ++i) {
			cin >> inp;
			binary_search(v.begin(), v.end(), inp) ? cout << "1\n" : cout << "0\n";
		}
	}

	return 0;
}


// 이진 탐색 함수 구현

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
vector<int> v;

bool BS(int target) {
	int L = 0, R = n - 1, mid;
	while (L <= R) {
		mid = (L + R) / 2;
		if (v[mid] == target) return true;
		else if (v[mid] < target) L = mid + 1;
		else /* v[mid] > target */ R = mid - 1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		v.clear();
		cin >> n;
		for (int inp, i = 0; i < n; ++i) { cin >> inp; v.push_back(inp); }
		sort(v.begin(), v.end());
		cin >> q;
		for (int inp, i = 0; i < q; ++i) {
			cin >> inp;
			BS(inp) ? cout << "1\n" : cout << "0\n";
		}
	}

	return 0;
}
