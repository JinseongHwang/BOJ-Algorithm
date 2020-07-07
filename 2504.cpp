// char 스택을 사용하면 쉽겠지만, 값이 두 자리수가 되면 사용 불가능하다.
// 따라서 구현 난이도가 체감상 상당히 높았다.
// 여는 괄호( '(', '[' )들을 -1과 -2로 처리한다고 하면 상당히 쉬워진다.
// 다만 떠올리지 못해 게시글을 참고하여 해결하였다.

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

bool isGoodBrackets(string input) {
	stack<char> s;
	for (int i = 0; i < input.length(); ++i) {
		if(input[i] == '(' || input[i] == '[') s.push(input[i]);
		else {
			if (!s.empty() && input[i] == ')' && s.top() == '(') s.pop();
			else if (!s.empty() && input[i] == ']' && s.top() == '[') s.pop();
			else return false;
		}
	}
	return (s.empty()) ? true : false;
}

int main() {
	init();
	string input; cin >> input;
	if (!isGoodBrackets(input)) {
		cout << "0\n";
		return 0;
	}

	stack<int> s;
	for (int i = 0; i < input.length(); ++i) {
		if (i < (input.length() - 1) && input[i] == '(' && input[i + 1] == ')') { s.push(2); i++; }
		else if (i < (input.length() - 1) && input[i] == '[' && input[i + 1] == ']') { s.push(3); i++; }
		else if (input[i] == '(') { s.push(-1); }
		else if (input[i] == '[') { s.push(-2); }
		else if (input[i] == ')') {
			int sum = 0;
			while (!s.empty() && s.top() != -1) {
				sum += s.top();
				s.pop();
			}
			s.pop();
			s.push(sum * 2);
		}
		else if (input[i] == ']') {
			int sum = 0;
			while (!s.empty() && s.top() != -2) {
				sum += s.top();
				s.pop();
			}
			s.pop();
			s.push(sum * 3);
		}
	}
	int result = 0;
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << "\n";
	
	return 0;
}
