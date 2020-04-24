#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;
const int ALPHABET = 26;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed; // 고정소수점 표기
	cout.precision(2); // 소수점 2자리까지 표기
}
int main() {
	init();
	int N; cin >> N;
	string str; cin >> str;
	int values[ALPHABET];
	for (int i = 0; i < N; i++) cin >> values[i];
	/* 입력 완료 */
	stack<double> s;
	for (int i = 0; i < str.length(); i++) {
		// 피연산자
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(values[str[i] - 'A']);
		}
		// 연산자 + - * /
		else {
			double x = s.top(); s.pop();
			double y = s.top(); s.pop();
			switch (str[i]) {
			case '+': s.push(y + x); break;
			case '-': s.push(y - x); break;
			case '*': s.push(y * x); break;
			case '/': s.push(y / x); break;
			}
		}
	}
	
	cout << s.top();

	return 0;
}
