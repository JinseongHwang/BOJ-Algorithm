/*에라토스테네스의 체*/
#include <iostream>
using namespace std;
#define MAX 1000001
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int M, N; cin >> M >> N;
	bool isPrime[MAX] = { 0, };
	isPrime[1] = true;
	for (int i = 2; i <= N; i++) {
		for (int j = i * 2; j <= N; j += i) {
			isPrime[j] = true;
		}
	}
	for (int i = M; i <= N; i++) 
		if (!isPrime[i]) cout << i << "\n";
	return 0;
}
