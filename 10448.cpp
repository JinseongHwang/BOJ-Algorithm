#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
vector<int> T;

bool is_Eureka(int input) {
	for (int i = 0; i < T.size(); ++i) {
		for (int j = i; j < T.size(); ++j) {
			if (binary_search(T.begin(), T.end(), input - T[i] - T[j]))
				return 1;
		}
	}
	return 0;
}

int main() {
	int testcase; scanf("%d", &testcase);

	int n = 1;
	while (1) { // 삼각수 저장
		int index = (n * (n + 1)) / 2;
		if (index >= MAX) break;
		T.push_back(index); n++;
	}
	
	while (testcase--) {
		int input; scanf("%d", &input);
		printf("%d\n", is_Eureka(input));
	}

	return 0;
}
