// 생태학 - 트라이로 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_ASCII = 96; // 32 ~ 127
int total; // 전체 종류 개수
vector<int> currStr; // 문자열 현황 저장

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

class Trie {
public:
	Trie* name[MAX_ASCII]; // 다음 문자를 가리키는 포인터 배열
	bool isLastNode; // 마지막 노드인지 판별
	int cnt; // 똑같은 문자열이 몇번 나왔는지 저장

	Trie() { // 생성자
		fill(name, name + MAX_ASCII, nullptr);
		isLastNode = false; cnt = 0;
	}

	// 굳이 소멸자가 필요없네?
	// ~Trie() {
	// 	for (int i = 0; i < MAX_ASCII; ++i)
	// 		if (name[i] != nullptr) delete name[i];
	// }

	void insert(char* str) { // 삽입
		if (*str == '\0') { // 마지막 문자일 경우
			total++; cnt++;
			isLastNode = true;
		}
		else { // 아직 중간이라면
			int currIdx = *str - ' '; // 필요한 ascii number로 변환
			if (name[currIdx] == nullptr) name[currIdx] = new Trie(); // 없다면 생성
			name[currIdx]->insert(str + 1); // 있었거나 생기면 재귀 생성
		}
	}

	// 처음부터 dfs로 탐색하면 정렬 필요없다
	// depth가 현재 문자열의 길이라고 봐도 무방하다.
	void dfsPrint(int depth) { 
		for (int i = 0; i < MAX_ASCII; ++i) {
			// 재귀 빠지면 문자열도 하나씩 빼주자.
			while (depth < currStr.size()) currStr.pop_back();

			if (isLastNode && depth) { // 마지막이고, 첫 문자 아니고
				cout << fixed;
				cout.precision(4); // 소수점 4자리 고정
				for (const auto& c : currStr) cout << (char)c; // 출력1
				cout << ' ' << ((double)cnt / total) * 100 << '\n'; // 출력2
				return;
			}
			if (name[i] == nullptr) continue;
			else { // name[i] != nullptr
				int currIdx = i + ' ';
				currStr.push_back(currIdx); // 문자 삽입
				name[i]->dfsPrint(depth + 1); // 재귀 탐색
			}
		}
	}
};

int main() {
	init();
	Trie* root = new Trie(); // 루트 생성

	// getline을 사용하기 위해 char* 와 string을 왔다갔다함
	char inp_c[31];
	string inp_str;
	while (getline(cin, inp_str)) {
		strcpy(inp_c, inp_str.c_str());
		root->insert(inp_c); // 문자열 삽입
	}
	root->dfsPrint(0); // 탐색 및 출력
	
	return 0;
}
