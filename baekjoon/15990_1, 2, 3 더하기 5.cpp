#include <iostream>

using namespace std;

const long long MAX = 1000000009;
int N;
long long dp[100001][4]; // dp[i][j] : i를 만들때 j가 마지막


void func() {
	dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0;
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MAX;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MAX;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MAX;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	func();
	
	while (T--) {
		cin >> N;
		cout << ((dp[N][1] + dp[N][2]) % MAX + dp[N][3]) % MAX << '\n';
	}

	return 0;
}