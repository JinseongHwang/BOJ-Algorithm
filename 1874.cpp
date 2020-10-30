#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<char> result;

int main() {
	int n; scanf("%d", &n);
	int currPush = 0;
	for (int inp, i = 0; i < n; ++i) {
		scanf("%d", &inp);
		if (!s.empty() && currPush > inp && s.top() < inp) {
			printf("NO");
			return 0;
		}
		while (currPush < inp) {
			currPush++;
			s.push(currPush);
			result.push_back('+');
		}
		if (!s.empty() && s.top() == inp) {
			s.pop();
			result.push_back('-');
			continue;
		}
		while (!s.empty() && s.top() != inp) {
			s.pop();
			result.push_back('-');
		}
	}
	for (const char& elem : result) printf("%c\n", elem);

	return 0;
}
