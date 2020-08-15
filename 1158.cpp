#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K, cnt = 0;
	cin >> N >> K;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) arr[i] = i;

	int idx = K - 1;
	cout << '<';
	while (1) {
		cout << arr[idx] + 1;
		if (++cnt == N) break;
		cout << ", ";
		arr.erase(arr.begin() + idx);
		idx--; // 하나 출력했으니 안밀리게 채워줌

		int nxt = 0;
		while (nxt < K) {
			idx++; nxt++;
			if (arr.size() <= idx) idx -= arr.size();
		}
	}
	cout << ">\n";

	return 0;
}
