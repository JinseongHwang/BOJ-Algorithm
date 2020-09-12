#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	vector<long long> v;
	for (int i = 0; i < N; ++i) {
		string inp; cin >> inp;
		reverse(inp.begin(), inp.end());
		v.push_back(stoll(inp));
	}
	sort(v.begin(), v.end());
	for (const long long& elem : v) cout << elem << "\n";

	return 0;
}
