#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void merge(int list[], int left, int mid, int right) {
	int sorted[100001];
	int x, y, z, i;
	x = left;
	y = mid + 1;
	z = left;

	while (x <= mid && y <= right) {
		if (list[x] <= list[y])
			sorted[z++] = list[x++];
		else
			sorted[z++] = list[y++];
	}

	if (x > mid) {
		for (i = y; i <= right; i++) {
			sorted[z++] = list[i];
		}
	}

	else {
		for (i = x; i <= mid; i++) {
			sorted[z++] = list[i];
		}
	}

	for (i = left; i <= right; i++) {
		list[i] = sorted[i];
	}
}

void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int binary_search(int x, int arr[], int N) {
	int start = 1;
	int end = N;
	int temp;

	while (end - start >= 0) {
		int mid = (start + end) / 2;
		
		if (arr[mid] > x) {
			end = mid - 1;
		}
		
		else if (arr[mid] < x) {
			start = mid + 1;
		}
		
		else {
			printf("1\n");
			return;
		}
		temp = 0;
	}
	printf("0\n");
	return;
}

int main(void) {
	int i, N, M, temp, arrN[100001];
	
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &arrN[i]);

	merge_sort(arrN, 1, N);

	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		scanf("%d", &temp);
		binary_search(temp, arrN, N);
	}

	return 0;
}