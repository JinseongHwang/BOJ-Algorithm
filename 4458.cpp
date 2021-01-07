#include <iostream>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;

	string bufferFlush; getline(cin, bufferFlush);
	while (N--) {
		string input; getline(cin, input);
		char& front = input.front();
		if ('a' <= front && front <= 'z') front -= 'a' - 'A';
		cout << input << '\n';
	}
	
	return 0;
}
