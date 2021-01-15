#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

const int MAX = 1e6 + 5;
const char* FAIL = "use the stairs";
int F, S, G, U, D, step[MAX];

void BFS() {
	queue<int> Q;
	Q.push(S);
	step[S] = 0;

	while (!Q.empty()) {
		int currFloor = Q.front();
		int currStep = step[currFloor];
		Q.pop();

		int upFloor = currFloor + U;
		int downFloor = currFloor - D;

		if ((1 <= upFloor && upFloor <= F) &&
			(step[upFloor] < 0)) {
			step[upFloor] = currStep + 1;
			Q.push(upFloor);
		}

		if ((1 <= downFloor && downFloor <= F) &&
			(step[downFloor] < 0)) {
			step[downFloor] = currStep + 1;
			Q.push(downFloor);
		}
		
		if (step[G] >= 0) break;
	}
}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	if (S == G) { // 출발지와 목적지가 동일
		printf("0\n");
		return 0;
	}

	if ((U == 0 && D == 0) || // 버튼 이동 값이 모두 0
		(U == 0 && S < G) || // 위로 못가는데, 목적지가 위에 있음
		(D == 0 && S > G)) { // 아래로 못가는데, 목적지가 아래에 있음
		printf("%s\n", FAIL);
		return 0;
	}
	
	memset(step, -1, sizeof(int) * (F + 1));
	BFS();
	step[G] < 0 ? printf("%s\n", FAIL) : printf("%d\n", step[G]);

	return 0;
}
