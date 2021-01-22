// 첫 번째 풀이
// 1276KB,  92MS

#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

const int MIN = 1e3;
const int MAX = 1e4;
const char* FAIL = "Impossible";
int from, to, result[MAX];
bool isPrime[MAX];

bool hasOneDiff(int a, int b) {
	int digitsA[4] = { 0, };
	int digitsB[4] = { 0, };
	int diffCnt = 0;

	for (int i = 0; i < 4; i++) {
		digitsA[i] = a % 10; a /= 10;
		digitsB[i] = b % 10; b /= 10;
		if (digitsA[i] != digitsB[i]) diffCnt++;
	}

	return diffCnt == 1 ? true : false;
}

void seive() {

	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
}

void BFS() {
	queue<int> Q;
	Q.push(from);

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (int nxt = MIN; nxt < MAX; nxt++) {
			// 소수가 아닌 경우 || 이미 방문한 경우 || 한 자리만 다른 경우가 아닌 경우
			if (!isPrime[nxt] || result[nxt] != 0 || !hasOneDiff(curr, nxt)) continue;

			Q.push(nxt);
			result[nxt] = result[curr] + 1;

			if (to == nxt) return;
		}
	}
}

int main() {
	int T; scanf("%d", &T);

	seive(); // 소수 판별

	while (T--) {
		scanf("%d %d", &from, &to);

		if (from == to) {
			printf("0\n");
			continue;
		}

		BFS(); // 탐색

		result[to] == 0 ? printf("%s\n", FAIL) : printf("%d\n", result[to]);

		memset(result, 0, sizeof(result));
	}

	return 0;
}


// 두 번째 풀이
// : 다음 소수를 판별하는 방법을 변경함. (블로그 참조)
// 1276KB,	0MS

#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

const int MIN = 1e3;
const int MAX = 1e4;
const char* FAIL = "Impossible";
int from, to, result[MAX];
bool isPrime[MAX];

int change(int src, const int& digit, const int& value) {
	// 정수 자리 쪼개기
	int digits[4] = { 0, };
	for (int i = 3; i >= 0; i--) {
		digits[i] = src % 10;
		src /= 10;
	}

	// 원하는 자리에 원하는 값으로 변경
	digits[digit] = value;

	// 변경된 값 반환
	return digits[0] * 1000
		+ digits[1] * 100
		+ digits[2] * 10
		+ digits[3];
}

void seive() {

	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
}

void BFS() {
	queue<int> Q;
	Q.push(from);

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (int digit = 0; digit < 4; digit++) { // 자리수 선택
			for (int i = 0; i < 10; i++) { // 각 자리수를 0~9로 변경해본다.

				int nxt = change(curr, digit, i);
				// 1000보다 작은 경우 || 소수가 아닌 경우 || 이미 방문한 경우 || 초기값과 같은 경우
				if (nxt < MIN || !isPrime[nxt] || result[nxt] != 0 || from == nxt) continue;

				Q.push(nxt);
				result[nxt] = result[curr] + 1;

				if (to == nxt) return;
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);

	seive(); // 소수 판별

	while (T--) {
		scanf("%d %d", &from, &to);

		if (from == to) {
			printf("0\n");
			continue;
		}

		BFS(); // 탐색

		result[to] == 0 ? printf("%s\n", FAIL) : printf("%d\n", result[to]);

		memset(result, 0, sizeof(result));
	}

	return 0;
}
