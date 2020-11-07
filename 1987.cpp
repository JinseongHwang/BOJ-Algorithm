
// 백트래킹 문제

#include <bits/stdc++.h>
using namespace std;

__inline int myAtoI(char upperCase) { return upperCase - 'A'; }

int R, C, dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
char board[20][20];
bool alphabet[26];
int result = 0;

void backtracking(int currR, int currC, int depth) {

	alphabet[myAtoI(board[currR][currC])] = true;
	for (int i = 0; i < 4; ++i) {
		int nxtR = currR + dr[i], nxtC = currC + dc[i];
		if (nxtR < 0 || nxtR >= R || nxtC < 0 || nxtC >= C) continue;
		if (alphabet[myAtoI(board[nxtR][nxtC])]) continue;
		backtracking(nxtR, nxtC, depth + 1);
	}
	alphabet[myAtoI(board[currR][currC])] = false;

	result = max(result, depth);
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) scanf(" %1c", &board[i][j]);
	backtracking(0, 0, 1);
	printf("%d\n", result);

	return 0;
}
