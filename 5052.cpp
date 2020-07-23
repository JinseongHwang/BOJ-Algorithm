// 5052 전화번호 목록 - 트라이

// C++11부터는 컴파일러에서 NULL을 0으로 치환해서 컴파일한다.
// 포인터 변수를 초기화 할 때 NULL보다 nullptr로 초기화하도록 하자.

#include <iostream>
#include <cstring>
using namespace std;

// 최대 단어의 개수, 전화번호의 최대 길이이자 숫자는 0부터 9까지 있다.
const int MAX_WORD = 10010, MAX_LEN = 10;
char num[MAX_WORD][MAX_LEN]; // 문자열을 저장하는 공간

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

class Trie {
private:
	Trie* word[MAX_LEN]; // 다음 문자를 가리키는 포인터 배열
	bool isLastNode; // 마지막 노드이면 true값을 가진다.
	bool nextNodeExist; // 자식 노드가 존재하면 true값을 가진다.

public:
	// 생성자
	Trie() { // 초기화 역할
		fill(word, word + MAX_LEN, nullptr);
		isLastNode = nextNodeExist = false;
	}
	// 소멸자
	~Trie() { // 메모리 누수 방지, 사용하고 나서 반납
		for (int i = 0; i < MAX_LEN; ++i)
			if (word[i] != nullptr) delete word[i];
	}
	// 문자열 삽입 연산
	void insert(char* currWord) {
		// 문자열의 마지막까지 탐색했다면
		if (*currWord == '\0') {
			isLastNode = true;
		}
		// 더 탐색할 문자열이 남아있다면
		else {
			int currNum = *currWord - '0';
			if (word[currNum] == nullptr) word[currNum] = new Trie(); // 동적할당
			nextNodeExist = true;
			word[currNum]->insert(currWord + 1); // 자식 노드 삽입
		}
	}
	// 일관성이 있는 문자열인지 판별
	bool consistent() {
		// 마지막 노드인데 다음 노드가 있는 경우 false
		if (isLastNode && nextNodeExist) return false;
		// 서브트리 중 일관성이 하나라도 없으면 false
		for (int i = 0; i < MAX_LEN; ++i) {
			if (word[i] != nullptr && !word[i]->consistent()) return false;
		}
		// 위 두 조건을 만족하지 않는다면 일관성이 있으므로 true
		return true;
	}
};

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		Trie* root = new Trie(); // 루트 생성
		for (int i = 0; i < n; ++i) {
			char input[MAX_LEN]; cin >> input; // 입력받음
			root->insert(input); // 문자열 삽입
		}
		cout << ((root->consistent()) ? "YES\n" : "NO\n");
		delete root; // 소멸
	}

	return 0;
}
