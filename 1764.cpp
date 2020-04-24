#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> arr, result;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	int n, m; scanf("%d %d", &n, &m);

	arr.resize(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr.begin(), arr.end());

	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (binary_search(arr.begin(), arr.end(), input)) {
			result.push_back(input);
		}
	}
	sort(result.begin(), result.end());

	printf("%d\n", result.size());
	for (int i = 0; i < result.size(); i++)
		printf("%s\n", result[i].c_str());
	
	return 0;
}
