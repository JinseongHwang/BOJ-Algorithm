#include <iostream>
using namespace std;
#define MAX 10000
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int N, M, s = 0, e = 0, sum = 0, result = 0;
	int arr[MAX] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i]; /*입력완료*/
	
	while (1) {
		if (e < s || s == N) break;
		if (sum == M) {
			result++;
			sum -= arr[s];
			s++;
		}
		else if (sum > M) {
			sum -= arr[s];
			s++;
		}
		else if (sum < M) {
			sum += arr[e];
			e++;
		}
	}
	cout << result << "\n";
	return 0;
}
