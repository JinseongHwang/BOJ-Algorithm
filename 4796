#include <iostream>
using namespace std;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int vacation, total, used, result, testcase = 1;
	while (1) {
		result = 0;
		cin >> used >> total >> vacation; // L P V
		if (!used && !total && !vacation) break;
		while (1) {
			if (vacation >= total) {
				vacation -= total;
				result += used;
			}
			else {
				if (vacation >= used) result += used;
				else result += vacation;
				break;
			}
		}
		cout << "Case " << testcase++ << ": " << result << "\n";
	}
	return 0;
}
