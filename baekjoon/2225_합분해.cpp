#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int total;
int dp[201][201];
int N, K;

void func(int n, int k) {
	if (k == 1) {
		dp[n][k] = 1;
		return;
	}
	int total = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[n - i][k - 1] == 0) {
			func(n - i, k - 1);
		}
		total += dp[n - i][k - 1];
		total %= 1000000000;
	}
	dp[n][k] = total;
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	func(N, K);
	cout << dp[N][K];

	return 0;
}