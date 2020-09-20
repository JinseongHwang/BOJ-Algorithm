/*
	참고: https://seokjin2.tistory.com/11
*/

#include <cstdio>
#include <vector>
using namespace std;

typedef long long int llt;
// 2차원 벡터를 matrix 타입으로 재정의
typedef vector<vector<llt> > matrix;
const llt MOD = 1e9 + 7;

// 행렬 A와 B를 곱하는 방법을 정의함(연산자 오버로딩)
matrix operator*(const matrix& a, const matrix& b) {
	// 행렬의 곱 성질에 따라, 좌측 행렬(A)의 행의 수를 'R'이라고 했을 때,
	// 곱 행렬 결과는 R * R 크기로 결정된다.

	llt R = a.size();
	matrix result(R, vector<llt>(R));
	for (llt i = 0; i < R; ++i)
		for (llt j = 0; j < R; ++j)
			for (llt k = 0; k < R; ++k)
				result[i][j] += (a[i][k] * b[k][j]) % MOD;

	return result;
}

matrix power(matrix a, llt n) {
	// 단위 행렬 생성
	llt R = a.size();
	matrix result(R, vector<llt>(R));
	for (llt i = 0; i < R; ++i) {
		result[i][i] = 1;
	}
	// 분할 정복을 활용한 빠른 거듭제곱 => O(log N)
	while (n > 0) {
		if (n % 2 == 1) {
			result = result * a;
		}
		n /= 2;
		a = a * a;
	}
	return result;
}

int main() {
	llt N; scanf("%lld", &N);
	matrix a = {
		{1, 1},
		{1, 0}
	};
	matrix result = power(a, N - 1);
	printf("%lld\n", (result[1][0] + result[1][1]) % MOD);

	return 0;
}
