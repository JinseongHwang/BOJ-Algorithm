#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int llt;

string otob(const char& c) {
	string bin;
	switch (c) {
	case '0': bin = "000"; break;
	case '1': bin = "001"; break;
	case '2': bin = "010"; break;
	case '3': bin = "011"; break;
	case '4': bin = "100"; break;
	case '5': bin = "101"; break;
	case '6': bin = "110"; break;
	case '7': bin = "111"; break;
	}
	return bin;
}

int main() {
	string input; cin >> input;
	string ans = "";
	for (auto iter = input.begin(); iter != input.end(); iter++) {
		ans += otob(*iter);
	}
	while (ans.length() > 1 && ans.front() == '0') {
		ans = ans.substr(1);
	}
	cout << ans << '\n';

	return 0;
}
