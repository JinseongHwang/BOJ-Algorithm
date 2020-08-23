#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<string> words;

	for (int i = 0; i < n; ++i) {
		string inp; cin >> inp;
		words.push_back(inp);
	}
	sort(words.begin(), words.end(), compare);

	// 중복제거를 하는 2가지 방법
	words.erase(unique(words.begin(), words.end()), words.end());
	// words.resize(unique(words.begin(), words.end()) - words.begin());
	for (const auto& res : words) cout << res << "\n";

	return 0;
}
