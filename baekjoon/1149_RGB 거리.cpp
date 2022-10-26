#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int color[1001][3];
int dp[1001][3];

int min(int x, int y) {
	if (x < y)
		return x;
	else
		return y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}

	dp[1][0] = color[1][0];
	dp[1][1] = color[1][1];
	dp[1][2] = color[1][2];
	
	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}

	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));


	return 0;
}