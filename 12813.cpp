#include <iostream>
#include <bitset>
using namespace std;

const int MAX = 1e5;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	bitset<MAX> a, b;
	cin >> a >> b;
	cout << (a & b) << '\n';
	cout << (a | b) << '\n';
	cout << (a ^ b) << '\n';
	cout << (~a) << '\n';
	cout << (~b) << '\n';

	return 0;
}
