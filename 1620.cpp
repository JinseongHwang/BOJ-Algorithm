#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <utility>
using namespace std;
typedef pair<string, int> psi;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	vector<psi> v1;
	vector<string> v2;
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		string input; cin >> input;
		v1.push_back(psi(input, i + 1));
		v2.push_back(input);
	}
	sort(v1.begin(), v1.end());

	while (q--) {
		string str; cin >> str;
		if (isalpha(str[0])) { // v1
			int L = 0, R = n - 1;
			while (L <= R) {
				int mid = (L + R) / 2;
				if (v1.at(mid).first == str) {
					cout << v1.at(mid).second << "\n";
					break;
				}
				else if (v1.at(mid).first < str) {
					L = mid + 1;
				}
				else {
					R = mid - 1;
				}
			}
		}
		else { // v2
			int index = stoi(str) - 1;
			cout << v2.at(index) << "\n";
		}
	}

	return 0;
}
