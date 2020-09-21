/*
	피사노 주기의 길이가 P 이면,
	N번째 피보나치 수를 M으로 나눈 나머지는 N % P 번째 피보나치 수를 M으로 나눈 나머지와 같다.

	참고: https://www.acmicpc.net/problem/9471
	P = k(10^n) = 15 * 10^(n-1)
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long int llt;

const llt MOD = 1e6;

llt Pisano_Period(llt N) {
	// n = log10(MOD) = 6
	// P = k(MOD) = 15 * 10^5
	const llt P = 15 * (1e5);
	N %= P;

	vector<llt> fibo(P, 0);
	fibo[0] = 0, fibo[1] = fibo[2] = 1;
	for (llt i = 3; i <= N; ++i) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	return (fibo[N]) % MOD;
}

int main() {
	llt N; scanf("%lld", &N);
	printf("%lld\n", Pisano_Period(N));
	return 0;
}
