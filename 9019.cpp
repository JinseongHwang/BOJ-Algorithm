#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1e4 + 5;
const char CMD[] = { 'D', 'S', 'L', 'R' };
int A, B;
vector<char> step[MAX];

int D(int reg) {
	int res = reg * 2;
	if (res > 9999) res %= 10000;
	return res;
}

int S(int reg) {
	if (reg == 0) return 9999;
	return reg - 1;
}

int L(int reg) {
	string res = to_string(reg);
	while (res.length() < 4) res = "0" + res; // 몰랐던 부분
	char f = res.front();
	res = res.substr(1);
	res.push_back(f);
	return stoi(res);
}

int R(int reg) {
	string res = "";
	string regStr = to_string(reg);
	while (regStr.length() < 4) regStr = "0" + regStr; // 몰랐던 부분
	res.push_back(regStr.back());
	res += regStr;
	res.pop_back();
	return stoi(res);
}

void BFS() {
	queue<int> Q;
	Q.push(A);
	// A 방문표시, 의미 없는 문자를 추가한다. (A와 B는 항상 다르기 때문에 상관없다.)
	step[A].push_back('.');

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		int results[] = { D(curr), S(curr), L(curr), R(curr) };
		for (int i = 0; i < 4; i++) {
			int nxt = results[i];
			if (!step[nxt].empty()) continue;
			step[nxt] = step[curr];
			step[nxt].push_back(CMD[i]);
			Q.push(nxt);
			if (!step[B].empty()) return;
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		
		BFS();

		for (int i = 1; i < step[B].size(); i++) {
			printf("%c", step[B][i]);
		}
		printf("\n");
		
		for (int i = 0; i < MAX; i++) {
			step[i].clear();
		}
	}

	return 0;
}
