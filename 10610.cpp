#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	string input; cin >> input;
	vector<int> each_num;
	long long int sum = 0;
	bool isZero = false;

	for (int i = 0; i < input.length(); i++) {
		int tmp = input[i] - '0';
		if (tmp == 0) isZero = true;
		sum += tmp;
		each_num.push_back(tmp);
	}

	if (!isZero || sum % 3 != 0) cout << "-1";
	else {
		sort(each_num.begin(), each_num.end());
		for (int i = each_num.size() - 1; i >= 0; i--)
			cout << each_num[i];
	}
	cout << "\n";

	return 0;
}
