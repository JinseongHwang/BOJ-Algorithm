
// 정렬
// github 업로드 안함

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

	//O(N) 두번 하는것보다 O(NlgN) 한번 해서 앞뒤 접근하는게 낫겠다.

	//int mx = *max_element(v.begin(), v.end());
	//int mn = *min_element(v.begin(), v.end());
	//printf("%d\n", mx * mn);

	sort(v.begin(), v.end());
	printf("%d\n", v.front() * v.back());

	return 0;
}
