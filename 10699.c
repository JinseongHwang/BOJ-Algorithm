#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int main() {
	int year, month, day;
	time_t now;
	time(&now);
	struct tm* local = localtime(&now);
	year = local->tm_year + 1900;
	month = local->tm_mon + 1;
	day = local->tm_mday;
	month < 10 ? printf("%d-0%d-%d\n", year, month, day) : printf("%d-%d-%d\n", year, month, day);
	return 0;
}
