#include <iostream>

using namespace std;

int N;
int dp[100001];

void func(int idx) {
	for (int i = 1; i * i <= idx; i++) {
		if (idx-i*i > 0 && dp[idx - i * i] == 0) {
			func(idx - i * i);
		}

		int temp = dp[idx - i * i] + 1;
		if (dp[idx] == 0 || dp[idx] > temp)
			dp[idx] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	func(N);
	cout << dp[N];

	return 0;
}