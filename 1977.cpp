#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
using namespace std;
enum {START, END};

int main() {
	int range[2];
	int minPSN, sumPSN = 0;
	bool findSuccess = false;
	scanf("%d %d", &range[START], &range[END]);
	for (int i = range[START]; i <= range[END]; ++i) {
		double currPSN = sqrt(i);
		if (currPSN - (int)currPSN == 0) {
			minPSN = i;
			findSuccess = true;
			break;
		}
	}
	if (!findSuccess) {
		printf("-1\n");
		return 0;
	}
	for (int i = minPSN; i <= range[END];) {
		sumPSN += i;
		i = pow(sqrt((double)i) + 1, 2.0);
	}
	printf("%d\n%d\n", sumPSN, minPSN);

	return 0;
}
