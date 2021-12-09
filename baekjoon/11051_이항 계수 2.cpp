#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];

int func(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	if (arr[n][r] > 0)
		return arr[n][r];
	return arr[n][r] = (func(n - 1, r - 1) + func(n - 1, r)) % 10007;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	cout << func(N, K);

	return 0;
}