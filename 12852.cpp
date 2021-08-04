#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int X;
int cnt;
int dp[1000001][2];

void min(int x, int y, int index, int y_index) {
	if (x > y) {
		dp[index][0] = y;
		dp[index][1] = y_index;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> X;
	cnt = 0;

	for (int i = 2; i <= X; i++) {
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = i-1;
		if (i % 3 == 0) {
			min(dp[i][0], dp[i / 3][0] + 1, i, i/3);
		}
		if (i % 2 == 0) {
			min(dp[i][0], dp[i / 2][0] + 1, i, i/2);
		}
	}

	cout << dp[X][0] << '\n' << X << " ";
	while (dp[X][1] >= 1) {
		cout << dp[X][1] << " ";
		X = dp[X][1];
	}




	return 0;
}