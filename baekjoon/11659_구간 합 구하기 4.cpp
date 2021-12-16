#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int temp, arr[100001];
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}

	for (int t = 0; t < M; t++) {
		int a, b, total = 0;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
	return 0;
}