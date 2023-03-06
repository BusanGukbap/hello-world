#include <iostream>
#include <vector>

using namespace std;

int N, len;
int dp[1001];
int A[1001];
vector<int> V;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int maxLen = 0, maxIdx = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		len = 0;

		for (int j = 1; j < i; j++) {
			if (A[j] < A[i])
				len = max(dp[j], len);
		}
		dp[i] = len + 1;

		if (maxLen < dp[i]) {
			maxLen = dp[i];
			maxIdx = i;
		}
	}

	for (int i = maxIdx; i >= 1; i--) {
		if (dp[i] == maxLen) {
			V.push_back(A[i]);
			maxLen--;
		}
	}
	
	cout << V.size() << '\n';
	while (!V.empty()) {
		cout << V.back() << ' ';
		V.pop_back();
	}

	return 0;
}