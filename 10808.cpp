#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string input; cin >> input;

	int alpha[26] = { 0, };
	for (const char& c : input) {
		alpha[c - 'a']++;
	}
	for (const int& elem : alpha) {
		cout << elem << " ";
	}

	return 0;
}
