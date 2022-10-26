#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans;
int coin[101];
int DP[10001];

void input() {
	cin >> N >> K;
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
}

void solution() {
	DP[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	cout << DP[K];

	return 0;
}