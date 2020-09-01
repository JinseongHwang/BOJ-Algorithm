#include <cstdio>
using namespace std;

int arr[10], result;

int main() {
	char c[8] = { 0, }; scanf("%s", c);
	
	int idx = 0;
	while (c[idx] != NULL) {
		int a = c[idx++] - '0';
		if (a == 6 || a == 9) {
			if (arr[6] < arr[9]) {
				arr[6]++;
				if (result < arr[6]) result = arr[6];
			}
			else {
				arr[9]++;
				if (result < arr[9]) result = arr[9];
			}
		}
		else {
			arr[a]++;
			if (result < arr[a]) result = arr[a];
		}
	}
	printf("%d\n", result);

	return 0;
}
