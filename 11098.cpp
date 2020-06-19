#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	int testcase; scanf("%d", &testcase);
	while (testcase--) {
		int numSP, currPrice, maxPrice = 0;
		string currName, maxName;
		scanf("%d", &numSP);
		while (numSP--) {
			scanf("%d", &currPrice);
			cin >> currName;
			if (maxPrice < currPrice) {
				maxPrice = currPrice;
				maxName = currName;
			}
		}
		cout << maxName << "\n";
	}

	return 0;
}
