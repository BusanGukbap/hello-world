#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void) {
	int N, i;
	scanf("%d", &N);

	int arr[1001];
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int min, max;
	if (arr[0] > arr[1]) {
		min = arr[1];
		max = arr[0];
	}
	else {
		min = arr[0];
		max = arr[1];
	}

	for (i = 2; i < N; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		else if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("%d\n", max - min);

	return 0;
}