#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int rope, result = 0;
	cin >> rope;
	int maxWeight[MAX] = { 0, };
	for (int i = 0; i < rope; i++) cin >> maxWeight[i];
	sort(maxWeight, maxWeight + rope, greater<int>());
	for (int i = 0; i < rope; i++) {
		int tmp = maxWeight[i] * (i + 1);
		if (result < tmp) result = tmp;
	}
	cout << result << "\n";
	return 0;
}
