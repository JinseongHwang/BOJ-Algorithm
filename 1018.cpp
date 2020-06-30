#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 51
char board[MAX][MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int minChanges(int r, int c) {
	int cntBS = 0, cntWS = 0, index = 1;
	// B로 시작하는 경우
	for (int i = r; i < r + 8; ++i) {
		for (int j = c; j < c + 8; ++j) {
			if (index % 2 != 0) { // B
				if (board[i][j] != 'B') cntBS++;
				index++;
			}
			else { // W
				if (board[i][j] != 'W') cntBS++;
				index++;
			}
		}
		index++; // 줄 바뀌면 색깔 규칙도 바꾸자
	}
	index = 1;
	// W로 시작하는 경우
	for (int i = r; i < r + 8; ++i) {
		for (int j = c; j < c + 8; ++j) {
			if (index % 2 != 0) { // W
				if (board[i][j] != 'W') cntWS++;
				index++;
			}
			else { // B
				if (board[i][j] != 'B') cntWS++;
				index++;
			}
		}
		index++;
	}
	return min(cntBS, cntWS);
}

int main() {
	init();
	int result = MAX * MAX;
	int n, m; cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	} // 입력완료

	for (int i = 0; i < n - 7; ++i) {
		for (int j = 0; j < m - 7; ++j) {
			// 탐색 시작 좌표 (i, j)
			result = min(result, minChanges(i, j));
		}
	}
	cout << result << "\n";

	return 0;
}
