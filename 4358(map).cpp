/*
set 과 map은 중복을 허용하지 않는다
기본적으로는 자동 정렬을 지원하는데,
unordered set || map 을 사용하면 자동 정렬을 하지 않는다. 그래서 더 빠르다.

set은 <key> 값 하나만을 가진다.
map은 <key, value> 값 두개만을 가진다.
key 값을 기준으로 정렬된다.
*/

// 4358 생태학

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string, double> mp;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	string input;
	int cnt = 0;

	//while (!cin.eof()) {
	//	getline(cin, input);
	//	if (input == "")break;
	//	mp[input]++;
	//	cnt++;
	//}

	while (getline(cin, input)) {
		mp[input]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);
	for (const auto& r : mp) {
		double currPerc = (double)(r.second / cnt) * 100;
		cout << r.first << " " << currPerc << "\n";
	}

	return 0;
}
