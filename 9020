#include <iostream>
using namespace std;
#define MAX 10001
void init() {
	ios_base::sync_with_stdio;
	cout.tie(0);
	cin.tie(0);
}
int main() {
	init();
	int testcase, max = 0, arr[MAX] = { 0, };
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	} /*입력 완료*/

	/*소수는 false의 index값*/
	bool isPrime[MAX] = { 0, }; isPrime[1] = true;
	for (int i = 2; i <= max; i++) {
		if (isPrime[i]) continue;
		for (int j = i * 2; j <= max; j += i) 
			isPrime[j] = true;
	} 

	for (int i = 0; i < testcase; i++) {
		int result[2] = { 0, MAX };
		for (int j = 2; j <= MAX / 2; j++) {
			if (!isPrime[j] && !isPrime[arr[i] - j]) {
				if (j > arr[i] - j) break;
				if(result[1] - result[0] > arr[i] - 2 * j)
					result[0] = j, result[1] = arr[i] - j;
			}
		}
		cout << result[0] << " " << result[1] << "\n";
	}
	return 0;
}
