#include <iostream>
using namespace std;

#define MAX 101
int len[MAX];

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
	for (int i = 0; i < n; ++i) cin >> len[i];
	for (int i = 1; i < n; ++i) {
		int g = gcd(len[0], len[i]);
		cout << len[0] / g << '/' << len[i] / g << "\n";
	}

	return 0;
}
