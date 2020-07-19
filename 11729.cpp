#include <iostream>
#include <cmath>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void hanoi(int from, int tmp, int to, int n) {
	// from에서 to로 n-1개의 탑을 옮기는데,
	// 과정에서 tmp를 사용함.
	// n이 1이 되면 그냥 옮긴다.
	if (n == 1) cout << from << " " << to << "\n";
	else {
		// from에서 to 거쳐 tmp로 옮기고,
		hanoi(from, to, tmp, n - 1);
		cout << from << " " << to << "\n";
		// tmp에서 from 거쳐 to로 옮긴다.
		hanoi(tmp, from, to, n - 1);
	}
}

int main() {
	init();
	int n; cin >> n;
	cout << (int)pow(2, n) - 1 << "\n";
	hanoi(1, 2, 3, n);
	
	return 0;
}
