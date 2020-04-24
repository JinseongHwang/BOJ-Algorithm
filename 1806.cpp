//맞는데 틀리는 소스(?)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int arr[MAX];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int N, S; cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int s = 0, e = 0, sum = 0, result = N + 1;
	while (s <= e && e < N) {
		if (sum < S) {
			if (e < N) sum += arr[e++];
		}
		else if (sum == S) {
			result = min(result, (e - s));
			sum += arr[e++];
		}
		else if (sum > S) {
			result = min(result, (e - s));
			sum -= arr[s++];
		}
	}
	if (result == N + 1) cout << "0\n";
	else cout << result << "\n";

	return 0;
}

//정답 소스코드
//#include <iostream>
//#include <algorithm>
//using namespace std;
//#define MAX 100000
//int arr[MAX];
//void init() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//}
//int main() {
//	init();
//	int N, S; cin >> N >> S;
//	for (int i = 0; i < N; i++) cin >> arr[i];
//
//	int s = 0, e = 0, sum = arr[0], result = N + 1;
//	while (s <= e && e < N) {
//		if (sum < S) {
//			if (e < N) sum += arr[++e];
//		}
//		else if (sum == S) {
//			result = min(result, (e - s + 1));
//			sum += arr[++e];
//		}
//		else if (sum > S) {
//			result = min(result, (e - s + 1));
//			sum -= arr[s++];
//		}
//	}
//	if (result == N + 1) cout << "0\n";
//	else cout << result << "\n";
//
//	return 0;
//}
