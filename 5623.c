#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int S[1000][1000];

int main(void) {
	int n, i, j;
	scanf("%d", &n);
	int result[1000];
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	if (n == 2) {
		result[0] = 1;
		result[1] = S[0][1] - 1;
	}
	else {
		int temp = S[0][1] + S[0][2] - S[1][2];
		result[0] = temp / 2;
		for (i = 1; i < n; i++) {
			result[i] = S[0][i] - result[0];
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}