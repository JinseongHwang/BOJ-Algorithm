#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 16
int L, C;
char list[MAX];
bool visit[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

bool satisfyPasswd() {
	int vowel = 0, consonant = 0;
	for (int i = 0; i < MAX; ++i) {
		if (visit[i]) {
			switch (list[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowel++;
				break;
			default:
				consonant++;
				break;
			}
		}
	}
	return (vowel >= 1 && consonant >= 2) ? true : false;
}

void dfs(int index, int count) {
	if (L == count && satisfyPasswd()) {
		for (int i = 0; i < MAX; ++i) {
			if (visit[i]) cout << list[i];
		} cout << "\n";
	}
	for (int i = index; i < C; ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, count + 1);
		visit[i] = false;
	}
}

int main() {
	init();
	cin >> L >> C;
	for (int i = 0; i < C; ++i) cin >> list[i];
	sort(list, list + C);

	dfs(0, 0);

	return 0;
}
