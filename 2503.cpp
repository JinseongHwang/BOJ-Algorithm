#include <iostream>
#include <string>
using namespace std;

bool results[1000];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void exceptions() {
	// 3자리가 아닌 수 (100 미만)는 관심없다.
	// 0을 포함하는 숫자거나
	// 세 자리가 모두 다르지 않은 숫자를 먼저 true로 찍어준다.
	for (int i = 100; i < 1000; ++i) {
		string curr = to_string(i);
		if (curr[1] == '0' || curr[2] == '0' || 
			curr[0] == curr[1] || curr[1] == curr[2] || curr[0] == curr[2]) results[i] = true;
	}
}

void game(int n, int s, int b) {
	// n에 대해서 s와 b조건이 맞지 않다면 true 찍어주자.
	string ns = to_string(n);
	for (int i = 100; i < 1000; ++i) {
		string curr = to_string(i);
		int currStrike = 0, currBall = 0;
		// strike 조건 탐색
		for (int j = 0; j < 3; ++j) {
			if (ns[j] == curr[j]) currStrike++;
		}
		if (s != currStrike) {
			results[i] = true;
			continue;
		}
		// ball 조건 탐색
		if (ns[0] == curr[1] || ns[0] == curr[2]) currBall++;
		if (ns[1] == curr[0] || ns[1] == curr[2]) currBall++;
		if (ns[2] == curr[0] || ns[2] == curr[1]) currBall++;
		if (b != currBall) results[i] = true;
	}
}

int main() {
	init();
	exceptions();

	int query; cin >> query;
	while (query--) {
		int n, s, b; cin >> n >> s >> b;
		game(n, s, b);
	}

	int cnt = 0;
	for (int i = 100; i < 1000; ++i) if (!results[i]) cnt++;
	cout << cnt << "\n";

	return 0;
}
