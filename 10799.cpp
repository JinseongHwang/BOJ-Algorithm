#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string input; cin >> input;

	int result = 0;
	stack<int> S;
	for (int i = 0; i < input.length(); i++) {
		const char& curr = input.at(i);
		if (curr == '(') { // 구간 시작
			S.push(i);
		}
		else {
			if (i > 0 && input[i - 1] == '(') { // 레이저
				S.pop();
				result += S.size();
			}
			else { // 구간 종료
				S.pop();
				result++;
			}
		}
	}
	cout << result << "\n";

	return 0;
}
