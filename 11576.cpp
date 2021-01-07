#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int A, B, m; scanf("%d %d %d", &A, &B, &m);
	vector<int> nums(m);
	for (int i = 0; i < m; i++) scanf("%d", &nums[i]);

	int decimal = 0, idx = 0;
	for (vector<int>::const_reverse_iterator iter = nums.crbegin(); iter != nums.crend(); iter++, idx++) {
		decimal += (*iter) * (int)pow(A, idx);
	}

	vector<int> ans;
	while (decimal > 0) {
		int R = decimal % B;
		decimal /= B;
		ans.emplace_back(R);
	}

	for (vector<int>::const_reverse_iterator iter = ans.crbegin(); iter != ans.crend(); iter++) {
		printf("%d ", *iter);
	}

	return 0;
}
