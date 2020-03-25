/* 연산 즉시 출력하기 */
#include <iostream>
#include <string>

using namespace std;

string input[64];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void quadTree(int sx, int sy, int ex, int ey, char symbol) {
	symbol = input[sy][sx];
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (input[i][j] != symbol) { // 분할 필요성을 느낌
				if (ex - sx <= 1 || ey - sy <= 1) { // 분할 불가
					cout << "(";
					cout << input[sy][sx];
					cout << input[sy][ex];
					cout << input[ey][sx];
					cout << input[ey][ex];
					cout << ")";
					return;
				}
				else { // 분할 시행
					cout << "(";
					int midx = (sx + ex) / 2, midy = (sy + ey) / 2;
					quadTree(sx, sy, midx, midy, symbol); // 좌상
					quadTree(midx + 1, sy, ex, midy, symbol); // 우상
					quadTree(sx, midy + 1, midx, ey, symbol); // 좌하
					quadTree(midx + 1, midy + 1, ex, ey, symbol); // 우하
					cout << ")";
					return;
				}
			}
		}
	}
	cout << symbol;
}
int main() {
	init();
	int n; cin >> n;
	string nonValue; getline(cin, nonValue); // 개행 버 빼기
	for (int i = 0; i < n; i++) 
		getline(cin, input[i]);
	/*입력완료*/
	quadTree(0, 0, n - 1, n - 1, input[0][0]);
	return 0;
}

/* Queue를 사용해서 한번에 출력하기 */
/*
#include <iostream>
#include <string>
#include <queue>

using namespace std;

string input[64];
queue<char> result;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void quadTree(int sx, int sy, int ex, int ey, char symbol) {
	symbol = input[sy][sx];
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (input[i][j] != symbol) { // 분할 필요성을 느낌
				if (ex - sx <= 1 || ey - sy <= 1) { // 분할 불가
					result.push('(');
					result.push(input[sy][sx]);
					result.push(input[sy][ex]);
					result.push(input[ey][sx]);
					result.push(input[ey][ex]);
					result.push(')');
					return;
				}
				else { // 분할 시행
					result.push('(');
					int midx = (sx + ex) / 2, midy = (sy + ey) / 2;
					quadTree(sx, sy, midx, midy, symbol); // 좌상
					quadTree(midx + 1, sy, ex, midy, symbol); // 우상
					quadTree(sx, midy + 1, midx, ey, symbol); // 좌하
					quadTree(midx + 1, midy + 1, ex, ey, symbol); // 우하
					result.push(')');
					return;
				}
			}
		}
	}
	result.push(symbol);
}
int main() {
	init();
	int n; cin >> n;
	string nonValue; getline(cin, nonValue); // 개행 버퍼 빼기
	for (int i = 0; i < n; i++) 
		getline(cin, input[i]); // 입력 완료
	
	quadTree(0, 0, n - 1, n - 1, input[0][0]);
	while (!result.empty()) {
		cout << result.front();
		result.pop();
	}
	return 0;
}
*/
