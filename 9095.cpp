#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void) {
	int T, n;
	cin >> T;
	int dp[12];
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 3; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n] << '\n';
	}

	return 0;
}