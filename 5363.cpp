#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string input; getline(cin, input);
		vector<string> words;
		string curr = "";
		for (const char& c : input) {
			if (c == ' ') {
				words.push_back(curr);
				curr = "";
				continue;
			}
			curr.push_back(c);
		}
		words.push_back(curr);

		int len = words.size();
		for (int i = 2; i < len; i++) {
			cout << words[i] << ' ';
		}
		cout << words[0] << ' ' << words[1] << '\n';
	}
	return 0;
}
