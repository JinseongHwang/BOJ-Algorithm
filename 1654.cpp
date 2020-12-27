#include <cstdio>
using namespace std;

typedef long long int ll;

const ll MAX = 1e4 + 10;
ll K, N, arr[MAX];

bool isEnough(ll len) {
	ll cnt = 0;
	for (ll i = 0; i < K; i++) {
		cnt += (arr[i] / len);
	}
	if (cnt < N) return false; // 부족할 경우
	return true;
}

int main() {
	scanf("%lld %lld", &K, &N);

	ll maxValue = -1;
	for (ll i = 0; i < K; i++) {
		scanf("%lld", arr + i);
		if (maxValue < arr[i]) maxValue = arr[i];
	}

	ll result = -1;
	ll L = 0, R = maxValue;
	while (L <= R) {
		ll mid = (L + R) / 2;
		if (mid == 0 || isEnough(mid)) {
			if (result < mid) result = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	printf("%lld\n", result);

	return 0;
}
