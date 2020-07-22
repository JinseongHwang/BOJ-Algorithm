#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	init();
	int n; cin >> n;
	vector<int> input, result;
	for (int a, i = 0; i < n; ++i) {
		cin >> a;
		input.push_back(a);
	}
	sort(input.begin(), input.end()); // 정렬

	/* 예를들어,
	6 / 4 => 몫: 1, 나머지: 2
	34 / 4 => 몫: 8, 나머지: 2
	38 / 4 => 몫: 9, 나머지: 2
	나누는 수를 m, 몫을 q_n, 나머지를 r 이라고 가정
	6, 34, 38 ... 를 a, b, c ... 라고 가정할 때,

	>> m과 r는 모든 식에서 동일하고, q_n은 다르다.
	a = q1 * m + r
	b = q2 * m + r
	c = q3 * m + r

	우리가 구해야 할 값은 m이다.
	동일한 r값을 제거하기 위해 가감법을 사용
	b - a = (q2 - q1) * m  => 28
	c - b = (q3 - q2) * m  => 4

	28과 4에는 자연수 m이 곱해져있다.
	따라서 m이 될 수 있는 최대공약수를 구해서 그 약수 집합 중
	2이상인 값들이 우리가 구하는 해이다.
	*/

	// 뒷 요소 - 앞 요소 값으로 bottom up 연산 후
	for (int i = 0; i < n - 1; ++i) {
		input[i] = input[i + 1] - input[i];
	}
	input.pop_back(); // 마지막 요소 pop

	int g; // 최대공약수 값을 저장
	if (input.size() == 1) { // 남아있는 요소의 개수가 1개일 때
		g = input[0];
	}
	else { // 남아있는 요소의 개수가 2개 이상일 때
		g = gcd(input[1], input[0]);
		// 모든 수의 최대공약수를 구함
		for (int i = 2; i < input.size(); ++i) g = gcd(input[i], g);
	}

	// 약수 구하기 알고리즘
	for (int i = 2; i * i <= g; ++i) {
		if (g % i == 0) {
			result.push_back(i);
			result.push_back(g / i);
		}
	}
	result.push_back(g);
	sort(result.begin(), result.end());
	// 중복값 제거
	result.erase(unique(result.begin(), result.end()), result.end());

	// 출력
	for (const int& i : result) cout << i << ' ';

	return 0;
}
