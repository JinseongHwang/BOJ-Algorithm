// C언어 소스코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*  delimiter, 구분자에 대한 이해가 필요하다
	scanf는 space, Tab, new line(\n) 등 공백문자를 구분자로 인식한다.
	fgets는 new line에 대해서만 구분자로 인식한다.
	따라서 이 문제는 fgets를 사용하면 해결할 수 있다. */
int main() {
	char input[101];
	while (fgets(input, 101, stdin)) {
		printf("%s", input);
	}
	return 0;
}

// ==============================================================
// C++ 소스코드
#include <iostream>
#include <string>
using namespace std;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	string input;
	while (getline(cin, input)) {
		cout << input << "\n";
	}
	return 0;
}
