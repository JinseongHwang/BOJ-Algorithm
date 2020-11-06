
// 백트래킹 문제

#include <bits/stdc++.h>
using namespace std;

int N, result, QList[15]; // QList[i]: i행에 Queen이 놓여있는 열

bool isProperPos(int nxtR, int nxtC) {
	for (int i = 0; i < nxtR; ++i) {
		int existR = i, existC = QList[i];
		if (existR == nxtR || existC == nxtC) return false;
		if (abs(existR - nxtR) == abs(existC - nxtC)) return false;
	}
	return true;
}

void solve(int currR) {
	if (currR == N) {
		result++;
		return;
	}
	
	for (int currC = 0; currC < N; ++currC) {
		if (!isProperPos(currR, currC)) continue;
		QList[currR] = currC;
		solve(currR + 1);
	}
}

int main() {
	// N*N 체스판 위에 N개의 퀸을 놓으려면 무조건 1개 행에 1개의 퀸만 자리할 수 있다.
	scanf("%d", &N);
	solve(0);
	printf("%d\n", result);
	return 0;
}

/*
1 -> 1
2 -> 0
3 -> 0
4 -> 2
5 -> 10
6 -> 4
7 -> 40
8 -> 92
9 -> 352
10 -> 724
11 -> 2680
12 -> 14200
13 -> 73712
14 -> 365596
*/
