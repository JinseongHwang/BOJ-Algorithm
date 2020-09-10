#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string str; getline(cin, str);
	for (int i = 0; i < str.length(); ++i) {
		int curr = str[i];
		if ('a' <= curr && curr <= 'z') {
			curr += 13;
			if (curr > 'z') curr -= 26;
			str[i] = curr;
		}
		else if ('A' <= curr && curr <= 'Z') {
			curr += 13;
			if (curr > 'Z') curr -= 26;
			str[i] = curr;
		}
		else continue;
	}
	cout << str << "\n";

	return 0;
}
