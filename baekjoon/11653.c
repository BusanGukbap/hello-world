#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int a, count = 2;
	scanf("%d", &a);

	while (a > 1) {
		if (a % count == 0) {
			printf("%d\n", count);
			a /= count;
		}
		else
			count++;
	}

	return 0;
}