#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10005;
string fibo[MAX];

string bigIntegerSum(string a, string b) {
	int num, carry = 0;
	string result;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() < b.length()) {
		a += '0';
	}
	while (a.length() > b.length()) {
		b += '0';
	}

	for (int i = 0; i < a.length(); ++i) {
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}

	reverse(result.begin(), result.end());

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	fibo[0] = "0", fibo[1] = "1", fibo[2] = "1";
	if (n < 3) {
		cout << fibo[n] << "\n";
		return 0;
	}
	for (int i = 3; i <= n; ++i) fibo[i] = bigIntegerSum(fibo[i - 1], fibo[i - 2]);
	cout << fibo[n] << "\n";

	return 0;
}
