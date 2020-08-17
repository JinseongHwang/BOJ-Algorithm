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

// 2020-08-17 추가
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, result = 0, arr[100010] = { 0, };
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; ++i) {
		int nrope = i + 1;
		int curr = arr[i] * nrope;
		if (result <= curr) result = curr;
	}
	cout << result << "\n";

	return 0;
}
