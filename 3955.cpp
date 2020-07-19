// 캔디 분배
// 확장 유클리드 알고리즘
// 참고: https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=221414840544&categoryNo=299&proxyReferer=&proxyReferer=https:%2F%2Fwww.google.co.kr%2F

#include <iostream>
using namespace std;
typedef long long int llt;
const llt MAX = 1e9;
llt k, c;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

llt gcd(llt a, llt b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	init();
	llt testcase; cin >> testcase;
	while (testcase--) {
		cin >> k >> c;

		// 한 봉지에 사탕 하나만 들어간다면,
		// 인원수 + 1 개의 사탕 봉지가 필요하다.
		// 만약 인원수 + 1이 MAX값보다 크다면 분배가 불가능하다.
		if (c == 1) {
			if (k + 1 > MAX) cout << "IMPOSSIBLE\n";
			else cout << k + 1 << "\n";
			continue;
		}

		// 1명이 사탕을 분배받는다면, 1봉지로 충분하다.
		if (k == 1) {
			cout << "1\n";
			continue;
		}

		// 만약 k와 c의 최대공약수가 1이 아니라면 분배가 불가능하다.
		if (gcd(k, c) != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		// 연산 과정
		llt tmp = 0, q = 0, r1 = k, r2 = c, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r2 * q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t2 * q;
		}
		// t1이 음수라면 인원수(k) 단위로 양수가 될 때까지 더해준다.
		while (t1 < 0) t1 += k;
		// 최대 범위를 초과하면 불가능한 상황이다.
		if (t1 > MAX) cout << "IMPOSSIBLE\n";
		// 아무 조건을 만족하지 않으면 분배 가능하다.
		else cout << t1 << "\n";
	}

	return 0;
}
