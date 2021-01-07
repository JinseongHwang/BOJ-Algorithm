#include <cstdio>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<int> S;

int getNext(int value, int P) {
	int ans = 0;
	while (value > 0) {
		int R = value % 10;
		value /= 10;
		ans += (int)pow(R, P);
	}
	return ans;
}

int main() {
	int A, P; scanf("%d %d", &A, &P);
	bool deleteMode = false;
	while (1) {
		if (deleteMode && S.find(A) == S.end()) break;
		if (S.find(A) != S.end()) {
			deleteMode = true;
			S.erase(A);
		}
		if (!deleteMode) S.insert(A);
		A = getNext(A, P);
	}
	printf("%d\n", S.size());
	
	return 0;
}
