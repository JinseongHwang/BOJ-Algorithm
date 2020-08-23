#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 5e5 + 10, INF = 8010;
int n, arr[MAX] = { 0, }, sum = 0;
vector<pii> freq(INF, pii(-INF, INF));

bool compare(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
		if (freq[arr[i] + 4000].first == -INF) freq[arr[i] + 4000].first = 0;
		freq[arr[i] + 4000] = { freq[arr[i] + 4000].first + 1, arr[i] };
	}
	sort(arr, arr + n);
	sort(freq.begin(), freq.end(), compare);
	int mid = n % 2 == 0 ? n / 2 - 1 : n / 2;
	int frequency = freq[0].first == freq[1].first ? freq[1].second : freq[0].second;

	cout << round((double)sum / n) << "\n";
	cout << arr[mid] << "\n";
	cout << frequency << "\n";
	cout << arr[n - 1] - arr[0] << "\n";

	return 0;
}
