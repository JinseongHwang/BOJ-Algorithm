#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string input; cin >> input;
	vector<string> postfixRepository;
	for (int i = 0; i < input.length(); i++) {
		string postfix(input, i);
		postfixRepository.push_back(postfix);
	}
	sort(postfixRepository.begin(), postfixRepository.end());
	for (const string& postfix : postfixRepository) {
		cout << postfix << '\n';
	}

	return 0;
}
