
// 덱 사용하는 문제

// 참고: https://www.acmicpc.net/board/view/25456
// 이 문제의 주안점은 reverse 명령이 들어왔다고 해서 reverse를 하는 것이 아니라, 
// reverse 연산을 수행했다고 가정하고 다른 연산들을 수행하는 것이다.

#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		// 입력
		int n; string cmd, arr; cin >> cmd >> n >> arr;  

		bool err = false; // error가 발생하면 true

		// ','와 ']'를 delimiter로 잡고 숫자를 dq에 push한다.
		string currNum = "";
		for (int i = 1; i < arr.length(); ++i) {
			if ((arr[i] == ',' || arr[i] == ']') && !currNum.empty()) {
				dq.push_back(atoi(currNum.c_str()));
				currNum = "";
			}
			else currNum += arr[i];
		}

		// 명령어 하나씩 읽으면서 수행하는데,
		// 'R'명령의 경우에는 홀수, 짝수일 경우로 나눠서 'D'연산을 조금 바꿔보자. -> 이 문제의 핵심
		int Rcnt = 0;
		for (const char& c : cmd) {
			if (c == 'R') Rcnt++;
			else {
				if (dq.empty()) {
					err = true; break;
				}
				if (Rcnt % 2) dq.pop_back();
				else dq.pop_front();
			}
		}
		
		// Rcnt가 홀수면 실제로 reverse를 하지말고 뒤에서부터 출력하자.
		if (err) cout << "error\n";
		else if (dq.empty()) cout << "[]\n";
		else if (Rcnt % 2) {
			cout << "[";
			for (int i = dq.size() - 1; i > 0; --i) cout << dq[i] << ",";
			cout << dq.front() << "]\n";
		}
		else {
			cout << "[";
			for (int i = 0; i < dq.size() - 1; ++i) cout << dq[i] << ",";
			cout << dq.back() << "]\n";
		}

		dq.clear();
	} // testcase end

	return 0;
}
