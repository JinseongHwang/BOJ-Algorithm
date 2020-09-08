#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 10;

__inline int ctoi(const char& a) { return a - '0'; }
__inline char itoc(const int& a) { return a + '0'; }
__inline bool carry(const char& a, const char& b) {
	if (ctoi(a) + ctoi(b) >= 10) return true;
	else return false;
}

int main() {
	//freopen("input.txt", "r", stdin);

	char a[MAX] = { 0, }, b[MAX] = { 0, }; scanf("%s %s", a, b);
	int alen = strlen(a), blen = strlen(b);
	if (alen < blen) { // a가 더 길거나 같게 설정한다
		swap(a, b);
		swap(alen, blen);
	}
	reverse(a, a + alen);
	reverse(b, b + blen);
	for (int i = 0; i < blen; ++i) {
		if (carry(a[i], b[i])) { // carry가 발생한 경우
			if (a[i + 1] == '\0') a[i + 1] = '1'; // 다음 자리수가 null일 경우
			else if (a[i + 1] == '9') { // 다음 자리수가 9라면 9들을 0으로 바꿔주고, 다음 자리수에 carry를 준다.
				int idx = i + 1;
				for (; a[idx] == '9'; ++idx)
					a[idx] = '0';
				a[idx] == '\0' ? a[idx] = '1' : a[idx]++;
			}
			else a[i + 1]++; // 위 조건들에 걸리지 않는 경우
			a[i] = itoc((ctoi(a[i]) + ctoi(b[i])) % 10); // carry를 발생시킨 자리수에 10 나머지값을 준다.
		}
		else { // carry가 발생하지 않은 경우
			a[i] = itoc(ctoi(a[i]) + ctoi(b[i]));
		}
	}
	alen = strlen(a); // 자리수가 더 길어진 경우
	for (int i = alen - 1; i >= 0; --i) printf("%c", a[i]);
	printf("\n");

	return 0;
}
