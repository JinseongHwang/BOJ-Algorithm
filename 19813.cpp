#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		string d; cin >> d;
		string DD = "", MM = "", YYYY = "";
		int idx = 0;
		if (d[1] == '.' || d[2] == '.') { // day.month.year
			for (const char& c : d) {
				if (c == '.') {
					idx++;
					continue;
				}
				switch (idx) {
				case 0: DD.push_back(c); break;
				case 1: MM.push_back(c); break;
				case 2: YYYY.push_back(c); break;
				}
			}
		}
		else { // month/day/year
			for (const char& c : d) {
				if (c == '/') {
					idx++;
					continue;
				}
				switch (idx) {
				case 0: MM.push_back(c); break;
				case 1: DD.push_back(c); break;
				case 2: YYYY.push_back(c); break;
				}
			}
		}
		while (DD.length() < 2) DD = "0" + DD;
		while (MM.length() < 2) MM = "0" + MM;
		while (YYYY.length() < 4) YYYY = "0" + YYYY;

		cout << DD << '.' << MM << '.' << YYYY << ' ' << MM << '/' << DD << '/' << YYYY << '\n';
	}

	return 0;
}
