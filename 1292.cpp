#include <iostream>
using namespace std;

const int MAX = 1010;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int S, E, arr[MAX] = { 0, };
	cin >> S >> E;

	int curr = 1;
	for (int i = 1; i <= E; ++i) {
		for (int j = 0; j < curr; ++j) {
			arr[i] = curr;
			i++;
			if (MAX <= i) break; // 런타임 에러 주범!
		}
		i--;
		curr++;
	}

	int sum = 0;
	for (int i = S; i <= E; ++i) {
		sum += arr[i];
	}
	cout << sum << "\n";

	return 0;
}
