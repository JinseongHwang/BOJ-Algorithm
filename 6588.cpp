#include <iostream>
using namespace std;

const int MAX = 1e6 + 1;
bool isPrime[MAX]; // prime == false

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void Eratos() {
	isPrime[1] = true;
	for (int i = 2; i < MAX; ++i) {
		if (isPrime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) {
			if (isPrime[j]) continue;
			isPrime[j] = true;
		}
	}
}

int main() {
	init();
	Eratos();
	int input;
	while (cin >> input) {
		bool check = false;
		if (!input) break;
		for (int i = 3; i < MAX; ++i) {
			if (!isPrime[i] && !isPrime[input - i]) {
				cout << input << " = " << i << " + " << input - i << "\n";
				check = true;
				break;
			}
		}
		if (!check) cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}
