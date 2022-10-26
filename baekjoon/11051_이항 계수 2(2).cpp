#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
		}
	}

	cout << arr[N][K];

	return 0;
}