#include <iostream>
using namespace std;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int input; cin >> input;
	int count = 0;
	bool* isPrime = (bool*)malloc(input * sizeof(bool) + sizeof(bool));
	fill(isPrime, isPrime + input + sizeof(bool), false);
	for (int i = 2; i <= input; i++) {
		if (isPrime[i]) continue;
		for (int j = i * 2; j <= input; j += i) {
			isPrime[j] = true;
		}
	}
	for (int i = 2; i <= input; i++) if (!isPrime[i]) count++;
		
	int* realPrime = (int*)malloc(count * sizeof(int));

	int tmp = 0;
	for (int i = 2; i <= input; i++) {
		/*이미 오름차순 정렬되어 있음*/
		if (!isPrime[i]) realPrime[tmp++] = i;
	}
	
	int s = 0, e = 0, sum = 0, result = 0;
	while (1) {
		if (e < s || s == count) break;
		if (sum == input) {
			result++;
			sum -= realPrime[s];
			s++;
		}
		else if (sum > input) {
			sum -= realPrime[s];
			s++;
		}
		else {
			sum += realPrime[e];
			e++;
		}
	}
	cout << result << "\n";
	free(isPrime);
	free(realPrime);
	return 0;
}
