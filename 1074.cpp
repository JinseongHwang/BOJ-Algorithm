#include <cstdio>
#include <cmath>
using namespace std;

int N, r, c, idx, result;
bool complete;

void DQ(int sr, int sc, int er, int ec) {
	if (complete) return;
	if (er - sr == 1 && ec - sc == 1) { // 분할 불가 - 값 부여
		if (sr == r && sc == c) { result = idx; complete = true; return; } idx++;
		if (sr == r && ec == c) { result = idx; complete = true; return; } idx++;
		if (er == r && sc == c) { result = idx; complete = true; return; } idx++;
		if (er == r && ec == c) { result = idx; complete = true; return; } idx++;
	}
	else { // 분할 필요
		int mr = (sr + er) / 2, mc = (sc + ec) / 2;
		DQ(sr, sc, mr, mc);
		DQ(sr, mc + 1, mr, ec);
		DQ(mr + 1, sc, er, mc);
		DQ(mr + 1, mc + 1, er, ec);
	}
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	DQ(0, 0, pow(2, N) - 1, pow(2, N) - 1);
	printf("%d\n", result);
	return 0;
}
