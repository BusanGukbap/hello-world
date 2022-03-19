#include <bits/stdc++.h>

using namespace std;

int dp[301];
int arr[301];
int N;

int bigger(int x, int y) {
	return (x > y) ? x : y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = bigger(arr[3] + arr[1], arr[3] + arr[2]);

	for (int i = 4; i <= N; i++) {
		dp[i] = bigger(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}
	
	cout << dp[N];

	return 0;
}