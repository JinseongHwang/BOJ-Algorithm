#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string num[4];
	for (int i = 0; i < 4; i++) cin >> num[i];
	cout << stoll(num[0] + num[1]) + stoll(num[2] + num[3]) << '\n';

	return 0;
}
