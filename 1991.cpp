#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int tree[1 << 21];
// A: 65
int find_root(char);
void preorder_traversal(int); // 전위순회
void inorder_traversal(int); // 중위순회
void postorder_traversal(int); // 후위순회
int main() {
	int n; scanf("%d", &n);
	int size = pow(2, (int)log2(n) + 1); // 첫번째 리프 노드의 번호

	int start;
	tree[1] = 'A'; // 루트 노드는 무조건 A라고 문제에 명시되어 있음
	for (int i = 0; i < n; ++i) {
		char a, b, c; scanf(" %c %c %c", &a, &b, &c); // 개행 버퍼 빼기 위해 %d 앞에 공백 추가함
		start = find_root(a); // 입력된 값이 어디부터 입력되어야 할지 노드 번호 반환
		/* 입력된 값이 알파벳이 아닌 . 이라면 0을 넣는다. */
		a >= 'A' && a <= 'Z' ? tree[start] = a : tree[start] = 0;
		b >= 'A' && b <= 'Z' ? tree[start * 2] = b : tree[start * 2] = 0;
		c >= 'A' && c <= 'Z' ? tree[start * 2 + 1] = c : tree[start * 2 + 1] = 0;
	}
	
	preorder_traversal(1); printf("\n");
	inorder_traversal(1); printf("\n");
	postorder_traversal(1); printf("\n");

	return 0;
}
int find_root(char c) {
	for (int i = 1;; ++i) {
		if (tree[i] == c) return i;
	}
}
void preorder_traversal(int start) {
	if (tree[start] == 0) return;
	printf("%c", tree[start]);
	preorder_traversal(start * 2);
	preorder_traversal(start * 2 + 1);
}
void inorder_traversal(int start) {
	if (tree[start] == 0) return;
	inorder_traversal(start * 2);
	printf("%c", tree[start]);
	inorder_traversal(start * 2 + 1);
}
void postorder_traversal(int start) {
	if (tree[start] == 0) return;
	postorder_traversal(start * 2);
	postorder_traversal(start * 2 + 1);
	printf("%c", tree[start]);
}
