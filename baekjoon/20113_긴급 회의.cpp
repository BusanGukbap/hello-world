#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101];



int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[temp]++;
	}

	int max1 = 0, max2 = 0, max1_idx;
	for (int i = 1; i <= N; i++) {
		if (max2 < arr[i])
			max2 = arr[i];
		if (max1 < max2) {
			int temp = max1;
			max1 = max2;
			max2 = temp;
			max1_idx = i;
		}
	}

	if (max1 == max2) {
		cout << "skipped";
	}
	else {
		cout << max1_idx;
	}

	return 0;
}