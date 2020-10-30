#include <bits/stdc++.h>
using namespace std;

list<char> li;
list<char>::iterator iter;

void L() {
	if (iter != li.begin()) iter--;
}
void D() {
	if (iter != li.end()) iter++;
}
void B() {
	if(iter != li.begin()) iter = li.erase(--iter);
}
void P(char c) {
	li.insert(iter, c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string input; cin >> input;
	for (const char& elem : input) {
		li.push_back(elem);
	}
	iter = li.end();
	int q; cin >> q;
	getline(cin, input); // 버퍼 비우기
	while (q--) {
		string query; getline(cin, query);
		char firstQuery = query[0];
		char PQuery;
		if (firstQuery == 'P') PQuery = query[2];
		switch (firstQuery) {
		case 'L': L(); break; // 왼쪽으로
		case 'D': D(); break; // 오른쪽으로
		case 'B': B(); break; // 하나 삭제
		case 'P': P(PQuery); break; // 하나 삽입
		}
	}
	for (iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter;
	}

	return 0;
}
