#include <iostream>
#include <string>
using namespace std;
enum {DAY, MONTH, YEAR};
const int INF = 1e9;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int n; cin >> n;
	string currName, maxName, minName;
	int currBD[3], maxBD[3], minBD[3];
	fill(maxBD, maxBD + 3, INF);
	fill(minBD, minBD + 3, 0);
	while (n--) {
		cin >> currName >> currBD[DAY] >> currBD[MONTH] >> currBD[YEAR];
		if (minBD[YEAR] < currBD[YEAR]) { 
			minName = currName;
			minBD[YEAR] = currBD[YEAR];
			minBD[MONTH] = currBD[MONTH];
			minBD[DAY] = currBD[DAY];
		}
		else if (minBD[YEAR] == currBD[YEAR]) {
			if (minBD[MONTH] < currBD[MONTH]) {
				minName = currName;
				minBD[YEAR] = currBD[YEAR];
				minBD[MONTH] = currBD[MONTH];
				minBD[DAY] = currBD[DAY];
			}
			else if (minBD[MONTH] == currBD[MONTH]) {
				if (minBD[DAY] < currBD[DAY]) {
					minName = currName;
					minBD[YEAR] = currBD[YEAR];
					minBD[MONTH] = currBD[MONTH];
					minBD[DAY] = currBD[DAY];
				}
			}
		}

		if (maxBD[YEAR] > currBD[YEAR]) {
			maxName = currName;
			maxBD[YEAR] = currBD[YEAR];
			maxBD[MONTH] = currBD[MONTH];
			maxBD[DAY] = currBD[DAY];
		}
		else if (maxBD[YEAR] == currBD[YEAR]) {
			if(maxBD[MONTH] > currBD[MONTH]) {
				maxName = currName;
				maxBD[YEAR] = currBD[YEAR];
				maxBD[MONTH] = currBD[MONTH];
				maxBD[DAY] = currBD[DAY];
			}
			else if (maxBD[MONTH] == currBD[MONTH]) {
				if(maxBD[DAY] > currBD[DAY]) {
					maxName = currName;
					maxBD[YEAR] = currBD[YEAR];
					maxBD[MONTH] = currBD[MONTH];
					maxBD[DAY] = currBD[DAY];
				}
			}
		}
	}
	cout << minName << "\n" << maxName << "\n";
	return 0;
}
