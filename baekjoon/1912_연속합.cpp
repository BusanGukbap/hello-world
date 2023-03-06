#include <iostream>

using namespace std;

int N;
int arr[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	int maxx = dp[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] > dp[i - 1] + arr[i])
			dp[i] = arr[i];
		else
			dp[i] = dp[i - 1] + arr[i];
		if (maxx < dp[i])
			maxx = dp[i];
	}
	cout << maxx;

	return 0;
}