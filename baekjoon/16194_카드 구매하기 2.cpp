#include <iostream>

using namespace std;

int P[1001];
int dp[1001]; // i장 샀을때 최대가격
int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int temp = dp[i - j] + P[j];
			if (dp[i] == 0)
				dp[i] = temp;
			else
				dp[i] = dp[i] < temp ? dp[i] : temp;
		}
	}

	cout << dp[N];

	return 0;
}