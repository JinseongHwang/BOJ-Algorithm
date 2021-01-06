#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string input;
	int lowerCnt, upperCnt, numCnt, spaceCnt;
	while (getline(cin, input)) {
		lowerCnt = upperCnt = numCnt = spaceCnt = 0;
		for (const char& c : input) {
			if ('a' <= c && c <= 'z') lowerCnt++;
			else if ('A' <= c && c <= 'Z') upperCnt++;
			else if ('0' <= c && c <= '9') numCnt++;
			else spaceCnt++;
		}
		cout << lowerCnt << ' ' << upperCnt << ' ' << numCnt << ' ' << spaceCnt << '\n';
	}
	

	return 0;
}
