#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void star(int i, int j, int num) {
	while (num != 0) {
		if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
			printf(" ");
			break;
		}
		else if (num / 3 == 0) {
			printf("*");
			break;
		}
		num /= 3;
	}
}

int main(void) {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			star(i, j, n / 3);
		}
		printf("\n");
	}

	return 0;
}