#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int N, B; scanf("%d %d", &N, &B);

	unordered_map<int, char> mp;
	char start = 'A';
	for (int i = 10; i < B; i++, start++) mp[i] = start;

	vector<char> ans;
	while (N > 0) {
		int R = N % B;
		N /= B;
		ans.push_back(R < 10 ? R + '0' : mp[R]);
	}

	for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) {
		printf("%c", *iter);
	}

	return 0;
}
