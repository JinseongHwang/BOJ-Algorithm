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
	vector<int> arr;
	int input; cin >> input;
	while (input > 0) {
		arr.push_back(input % 10);
		input /= 10;
	}
	
	sort(arr.begin(), arr.end(), greater<>());

	for (const auto& value : arr) cout << value;
	cout << "\n";
	return 0;
}
