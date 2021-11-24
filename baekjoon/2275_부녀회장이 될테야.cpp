#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int T;
int K, N;
int arr[15][15];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 14; i++) {
		arr[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	cin >> T;
	while (T--) {
		cin >> K >> N;
		cout << arr[K][N] << '\n';
	}

	return 0;
}