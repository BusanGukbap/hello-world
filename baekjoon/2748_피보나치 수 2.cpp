#include <bits/stdc++.h>

using namespace std;

long long int dp[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	dp[1] = 1; dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << '\n';

	return 0;
}