#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int a, b, N, i, count = 0;
	scanf("%d", &N);
	int arrN[101];

	for (i = 1; i <= N; i++) {
		arrN[i] = -1;
	}

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		if (arrN[a] == -1) {
			arrN[a] = b;
		}
		else if (arrN[a] != b) {
			arrN[a] = b;
			count++;
		}
	}
	printf("%d", count);

	return 0;
}
