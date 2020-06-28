#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int tall[9], faker[2], sum = 0;
	vector<int> honest;
	for (int i = 0; i < 9; ++i) {
		cin >> tall[i];
		sum += tall[i];
	}
	sum -= 100;

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (tall[i] + tall[j] == sum) {
				faker[0] = i; faker[1] = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; ++i) {
		if (i == faker[0] || i == faker[1]) continue;
		honest.push_back(tall[i]);
	}
	sort(honest.begin(), honest.end());

	for (int i = 0; i < honest.size(); ++i) cout << honest.at(i) << "\n";

	return 0;
}
