#include <cstdio>

typedef long long int llt;

int main() {
	int N; scanf("%d", &N);
	while (N--) {
		llt num1, num2, result; char op;
		scanf("%lld %c %lld = %lld", &num1, &op, &num2, &result);
		llt correctResult = 0;
		switch (op) {
		case '+':
			correctResult = num1 + num2;
			break;
		case '-':
			correctResult = num1 - num2;
			break;
		case '*':
			correctResult = num1 * num2;
			break;
		case '/':
			correctResult = num1 / num2;
			break;
		}
		if (correctResult == result) {
			printf("correct\n");
		}
		else {
			printf("wrong answer\n");
		}
	}

	return 0;
}
