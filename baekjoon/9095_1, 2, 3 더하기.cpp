#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void) {
	int T, N;
	cin >> T;
	
	int dp[12];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}