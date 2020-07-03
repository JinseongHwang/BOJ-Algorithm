// 각 단어별로 새로 배워야하는 알파벳의 종류를 알아내자
// 배움이 필요한 알파벳들의 k-5개씩 부분집합들을 만든다.
// 모든 집합 각각 learned 범위 내에서 읽을 수 있는 단어 개수들 중 최대값 출력

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> vs; // 입력 받은 단어들을 저장
vector<int> nl; // 배워야 할 단어의 목록을 저장
int n, k, result = 0;
bool learned[26], needLearn[26];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	learned['a' - 'a'] = true;
	learned['n' - 'a'] = true;
	learned['t' - 'a'] = true;
	learned['i' - 'a'] = true;
	learned['c' - 'a'] = true;
}

void howManyRead() {
	int currResult = n;
	for (int i = 0; i < vs.size(); ++i) {
		for (int j = 4; j < vs[i].length() - 4; ++j) {
			// i번째 문자열의 j번째 문자 하나라도 배우지 않은게 있는가?
			if (!learned[vs[i][j] - 'a']) {
				currResult--; break;
			}
		}
	}
	result = max(result, currResult);
}

void dfs(int index, int count) {
	// nl배열 안에 저장된 문자들로 k개의 조합을 구성하고,
	// howManyRead() 함수를 호출해서 result에 최대 개수를 갱신한다.
	if (count == k) {
		howManyRead(); return;
	}
	for (int i = index; i < nl.size(); ++i) {
		if (learned[nl[i]]) continue;
		learned[nl[i]] = true;
		dfs(i, count + 1);
		learned[nl[i]] = false;
	}
}

int main() {
	init();
	cin >> n >> k;
	k -= 5;
	
	for (int i = 0; i < n; ++i) {
		string word; cin >> word; vs.push_back(word);

		if (k < 0) { // 최소한 5개는 알아야지 남극 단어를 읽을 수 있다.
			cout << "0\n";
			return 0;
		}
		
		for (int j = 4; j < word.length() - 4; ++j) {
			// 배우지 않은 알파벳이라면 needLearn에 true 찍어준다.
			if (word[j] != 'a' && word[j] != 'n' && word[j] != 't' && word[j] != 'i' && word[j] != 'c')
				needLearn[word[j] - 'a'] = true;
		}
	}

	for (int i = 0; i < 26; ++i) {
		// nl에는 배움이 필요한 알파벳들이 저장된다.
		if (needLearn[i]) nl.push_back(i);
	}
	
	// n개를 배울 수 있는데 배울 필요가 있는 알파벳이 n개보다 적은 경우
	if (k > nl.size()) {
		cout << vs.size() << "\n";
		return 0;
	}
	else {
		dfs(0, 0);
		cout << result << "\n";
		return 0;
	}
}
