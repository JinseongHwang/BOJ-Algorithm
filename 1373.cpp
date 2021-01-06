#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string input; cin >> input;
	string num = "";
	int len = input.length();
	while (len % 3) {
		num.push_back('0');
		len++;
	}
	num += input; // 자리수를 3의 배수로 만들어줌

	for (int i = 0; i < num.length(); i += 3) {
		int curr = 0;
		for (int j = 2; j >= 0; j--) curr += (num[i + 2 - j] - '0') * (int)pow(2, j);
		cout << curr;
	}
	
	return 0;
}
