#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int input[301];
int dp[301];

int max(int x, int y){
	if (x > y)
		return x;
	else
		return y;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];
	
	dp[0] = 0;
	dp[1] = input[1];
	dp[2] = input[1] + input[2];
	dp[3] = max(input[3] + input[1], input[2] + input[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]);
	}

	cout << dp[N];


	return 0;
}