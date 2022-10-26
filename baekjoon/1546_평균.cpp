#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double N, res = 0, arr[1000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	double maxVal;
	maxVal = *max_element(arr, arr + (int)N);
	for (int i = 0; i < N; i++) {
		res += arr[i] * 100 / maxVal;
	}
	cout << res / N;

	return 0;
}