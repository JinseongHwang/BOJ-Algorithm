// 비효율적인 소스코드
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

const int MAX = 1501;
int arr[MAX][MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

typedef struct Data {
	// 값, 열, 행
	int value, column, row;
} Data;

bool operator<(Data a, Data b) {
	// 값 기준 정렬
	return a.value < b.value; // 최대 힙
}

int main() {
	init();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	// 마지막 행 모든 요소 pq에 삽입
	// 가장 큰 값 빼고, 그 값의 윗 값 삽입
	// n번 반복
	priority_queue<Data, vector<Data> > pq;
	for (int i = 0; i < n; ++i) {
		Data inp = { arr[n - 1][i], i, n - 1 };
		pq.push(inp); // 초기 삽입
	}
	
	int cnt = 1;
	while (1) {
		int currValue = pq.top().value, currCol = pq.top().column, currRow = pq.top().row;
		pq.pop();
		if (cnt == n) {
			cout << currValue << '\n';
			break;
		}
		Data inp = { arr[currRow - 1][currCol], currCol, currRow - 1 };
		pq.push(inp);
		cnt++;
	}

	return 0;
}
