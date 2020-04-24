#pragma warning (disable : 4996)
#include <cstdio>
int main() {
	int A, B, V; scanf("%d %d %d", &A, &B, &V);
	int result;
	if ((V - B) % (A - B) == 0) result = (V - B) / (A - B);
	if ((V - B) % (A - B) != 0) result = (V - B) / (A - B) + 1;
	printf("%d\n", result);
	return 0;
}
