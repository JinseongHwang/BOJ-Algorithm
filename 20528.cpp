#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	int result = 1;
	char symbol;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (i == 0) {
			symbol = input.front();
			continue;
		}
		if (symbol != input.front()) {
			result = 0;
		}
	}

	cout << result << "\n";

	return 0;
}
