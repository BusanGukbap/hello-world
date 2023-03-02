#include <iostream>

using namespace std;

int N;
double arr[10001];
double dp[10001];
double maxx = -1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			dp[i] = arr[i];
			continue;
		}

		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		maxx = max(maxx, dp[i]);
	}

	printf("%.3f\n", maxx);
	return 0;
}