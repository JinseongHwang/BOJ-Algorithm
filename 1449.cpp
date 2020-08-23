#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, L; cin >> N >> L;
	int pos[1010] = { 0, };
	for (int i = 0; i < N; ++i) cin >> pos[i];
	sort(pos, pos + N);
	
	// 물이 새는 곳 좌우 0.5만큼 더 붙인다는 개념을
	// 새는 곳의 뒤에 1만큼 더 붙여야 된다고 생각하자.
	// int 타입으로 깔끔하게 연산하기 위해서이다.

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int coverable = pos[i] + L - 1; // L - 1만큼의 차이는 하나의 테이프로 붙이기 가능
		result++;
		do i++;
		while (pos[i] <= coverable);
		i--;
	}
	cout << result << "\n";

	return 0;
}
