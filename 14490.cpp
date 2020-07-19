// C header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C++ header
#include <iostream>
#include <string>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	/* >>> 풀이1: strtok를 사용함
	char input[11]; scanf("%s", input);
	char* L_c = strtok(input, ":");
	char* R_c = strtok(NULL, ":");
	int a = atoi(L_c), b = atoi(R_c);
	int g = (a >= b) ? gcd(a, b) : gcd(b, a);
	printf("%d:%d\n", a / g, b / g); */

	/* >>> 풀이2: scanf 입력 형식을 바꿈
	int a, b; scanf("%d:%d", &a, &b);
	int g = (a >= b) ? gcd(a, b) : gcd(b, a);
	printf("%d:%d\n", a / g, b / g); */

	// >>> 풀이3: substr를 사용함
	init();
	string s; cin >> s;
	int colonPos = s.find(':');
	string L = s.substr(0, colonPos);
	string R = s.substr(colonPos + 1, s.length());
	int a = stoi(L), b = stoi(R);
	int g = (a >= b) ? gcd(a, b) : gcd(b, a);
	cout << a / g << ':' << b / g << '\n';

	return 0;
}
