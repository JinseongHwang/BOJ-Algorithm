#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
	string N; cin >> N;
	int B; cin >> B;

	unordered_map<char, int> mp;
	char start = 'A';
	for (int i = 10; i < B; i++, start++) mp[start] = i;

	int ans = 0, digit = 0;
	for (auto iter = N.rbegin(); iter != N.rend(); iter++, digit++) {
		const char& curr = *iter;
		if ('0' <= curr && curr <= '9') {
			ans += (curr - '0') * (int)pow(B, digit);
		}
		else {
			ans += mp[curr] * (int)pow(B, digit);
		}
	}
	cout << ans;

	return 0;
}
