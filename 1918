#include <iostream>
#include <string>
#include <stack>
using namespace std;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	string input; cin >> input;
	stack<char> repository;
	
	for (int i = 0; i < input.length(); i++) {
		// 피연산자 ('A' ~ 'Z')
		if (input[i] >= 'A' && input[i] <= 'Z') {
			cout << input[i];
		}
		// 연산자 + - * /
		else {
			switch (input[i]) {
			case '(':
				repository.push(input[i]);
				break;
			case '*':
			case '/':
				while (!repository.empty() && (repository.top() == '*' || repository.top() == '/')) {
					cout << repository.top();
					repository.pop();
				}
				repository.push(input[i]);
				break;
			case '+':
			case '-':
				while (!repository.empty() && repository.top() != '(') {
					cout << repository.top();
					repository.pop();
				}
				repository.push(input[i]);
				break;
			case ')':
				while (!repository.empty() && repository.top() != '(') {
					cout << repository.top();
					repository.pop();
				}
				repository.pop();
				break;
			}
		}
	}
	while (!repository.empty()) {
		cout << repository.top();
		repository.pop();
	}
	return 0;
}
