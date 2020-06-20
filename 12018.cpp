#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int numSubject, ownMileage; cin >> numSubject >> ownMileage;
	vector<int> minMileage;
	for (int i = 0; i < numSubject; ++i) {
		int request, limit; cin >> request >> limit;
		vector<int> v;
		for (int currMileage, j = 0; j < request; ++j) {
			cin >> currMileage;
			v.push_back(currMileage);
		}
		sort(v.begin(), v.end(), greater<int>());
		int currMin = ((int)v.size() < limit) ? v.back() : v[limit - 1];
		if (request < limit) { currMin = 1; } // 질문글 보고 추가한 내용
		minMileage.push_back(currMin);
	}
	sort(minMileage.begin(), minMileage.end());
	int result = 0;
	for (int i = 0; i < (int)minMileage.size(); ++i) {
		if (ownMileage - minMileage[i] >= 0) {
			ownMileage -= minMileage[i];
			result++;
		}
		else break;
	} 
	cout << result << "\n";

	return 0;
}
