#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 4500;
int arr[MAX] = { 0,1,0, };

int main() {
	int x; scanf("%d", &x);

	if (x == 1) {
		printf("1/1\n");
		return 0;
	}
	
	int adder = 4;
	for (int i = 2; i < MAX; ++i) {
		if (i % 2 == 0) {
			arr[i] += (arr[i - 1] + 1);
		}
		else {
			arr[i] += (arr[i - 1] + adder);
			adder += 4;
		}
	}

	for (int i = 3; i < MAX; i += 2) {
		int L = arr[i - 1], R = arr[i];
		if (L <= x && x <= R) {
			int mid = (L + R) / 2;
			if (x < mid) { // L line
				int diff = x - L;
				int row = diff + 1, col = i - diff - 1;
				printf("%d/%d\n", row, col);
			}
			else { // R line
				int diff = R - x;
				int row = diff + 1, col = i - diff;
				printf("%d/%d\n", row, col);
			}
			break;
		}
	}

	return 0;
}
