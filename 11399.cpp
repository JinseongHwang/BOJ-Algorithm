#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, arr[1010] = { 0, }, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 1; i < n; ++i) {
		arr[i] += arr[i - 1];
		sum += arr[i - 1];
	} 
	sum += arr[n - 1];
	cout << sum << '\n';

	return 0;
}
