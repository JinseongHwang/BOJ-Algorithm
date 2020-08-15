// 처음 고안해낸 방법 - 벡터를 사용해서 조건에 맞는 요소를 삭제해나감
// 약소하게 빠름

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


// 정해라고 판단됨 - 큐를 이용한 풀이.
// 훨씬 간결하고 직관적임
// 벡터를 사용했을 때보다 조금 느림
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; ++i) q.push(i);

	cout << '<';
	while (1) {
		if (q.size() == 1) {
			cout << q.front() << ">\n";
			break;
		}
		for (int i = 0; i < K - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}
