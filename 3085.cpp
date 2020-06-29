#include <iostream>
using namespace std;

#define MAX 51
char board[MAX][MAX];
int currSize, result;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

int maxLength() {
	int currMax = 1, resultMax = 0;
	char currChar;
	for (int i = 0; i < currSize; ++i) { // 가로줄 탐색
		currChar = board[i][0];
		currMax = 1;
		for (int j = 0; j < currSize; ++j) {
			if (j == 0) continue;
			if (currChar == board[i][j]) {
				currMax++;
				if (resultMax < currMax) resultMax = currMax;
			}
			else {
				currChar = board[i][j];
				currMax = 1;
			}
		}
	}
	
	for (int i = 0; i < currSize; ++i) { // 세로줄 탐색
		currChar = board[0][i];
		currMax = 1;
		for (int j = 0; j < currSize; ++j) {
			if (j == 0) continue;
			if (currChar == board[j][i]) {
				currMax++;
				if (resultMax < currMax) resultMax = currMax;
			}
			else {
				currChar = board[j][i];
				currMax = 1;
			}
		}
	}
	return resultMax;
}

int main() {
	init();
	cin >> currSize;
	for (int i = 0; i < currSize; ++i)
		for (int j = 0; j < currSize; ++j)
			cin >> board[i][j];

	int currMax;
	for (int i = 0; i < currSize; ++i) {
		for (int j = 0; j < currSize; ++j) {
			if (board[i][j] != board[i][j + 1] && j + 1 < currSize) {
				swap(board[i][j], board[i][j + 1]); // x축 위에서 좌우교환
				currMax = maxLength();
				if (result < currMax) result = currMax;
				swap(board[i][j], board[i][j + 1]); // 되돌리기
			}
			if (board[i][j] != board[i + 1][j] && i + 1 < currSize) {
				swap(board[i][j], board[i + 1][j]); // y축 위에서 상하교환
				currMax = maxLength();
				if (result < currMax) result = currMax;
				swap(board[i][j], board[i + 1][j]); // 되돌리기
			}
		}
	}
	cout << result << "\n";

	return 0;
}
