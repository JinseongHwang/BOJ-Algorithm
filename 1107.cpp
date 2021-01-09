//#include <cstdio>
//#include <cmath>
//using namespace std;
//
//const int INF = 1e6;
//int ch, m;
//bool broken[10];
//
//int getNumberOfDigits(int N) {
//	int idx = 1; // 입력된 값의 자리수
//	for (; idx < 7; idx++) {
//		if (N - static_cast<int>(pow(10, idx)) < 0) {
//			break;
//		}
//	}
//	return idx;
//}
//
//bool isUsable(int N) {
//	while (N > 0) {
//		int R = N % 10;
//		N /= 10;
//		if (broken[R]) return false;
//	}
//	return true;
//}
//
//int main() {
//	scanf("%d %d", &ch, &m);
//	for (int i = 0; i < m; i++) {
//		int br; scanf("%d", &br);
//		broken[br] = true;
//	}
//
//	if (m == 10) {
//		printf("%d\n", abs(ch - 100));
//		return 0;
//	}
//
//	int idx = getNumberOfDigits(ch);
//	int firstNum = ch / static_cast<int>(pow(10, idx - 1));
//
//	int start, end;
//	if (firstNum <= 1) {
//		if (idx <= 2) start = 0;
//		else start = 9 * static_cast<int>(pow(10, idx - 2));
//		end = (firstNum + 1) * static_cast<int>(pow(10, idx - 1));
//	}
//	else {
//		start = (firstNum - 1) * static_cast<int>(pow(10, idx - 1));
//		end = (firstNum + 1) * static_cast<int>(pow(10, idx - 1));
//	}
//	
//	int minDiff = INF, minDiffNum = 0;
//	for (int curr = start; curr <= end; curr++) {
//		if (isUsable(curr)) {
//			printf("%d ", curr);
//			int diff = abs(ch - curr);
//			if (minDiff > diff) {
//				minDiff = diff;
//				minDiffNum = curr;
//			}
//		}
//	}
//
//	int result = abs(ch - minDiffNum);
//
//	if (minDiffNum == 0) result++;
//	while (minDiffNum > 0) {
//		minDiffNum /= 10;
//		result++;
//	}
//
//	int foolResult = abs(ch - 100);
//
//	printf("%d\n", result < foolResult ? result : foolResult);
//
//	return 0;
//}

#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

const int INF = 0x7fffffff;
int ch, m;
bool broken[10];

bool isUsable(int N) {
	if (N == 0) return !broken[0];
	while (N > 0) {
		int R = N % 10;
		N /= 10;
		if (broken[R]) return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &ch, &m);
	for (int i = 0; i < m; i++) {
		int br; scanf("%d", &br);
		broken[br] = true;
	}

	if (m == 10) {
		printf("%d\n", abs(ch - 100));
		return 0;
	}

	int minDiffNum, minDiff = INF;
	for (int i = 0; i <= static_cast<int>(1e6); i++) {
		if (isUsable(i)) {
			int diff = abs(ch - i);
			if (minDiff > diff) {
				minDiff = diff;
				minDiffNum = i;
			}
		}
	}

	int jmpRes = to_string(minDiffNum).length() + abs(ch - minDiffNum);
	int sftRes = abs(ch - 100);
	printf("%d\n", jmpRes < sftRes ? jmpRes : sftRes);

	return 0;
}
