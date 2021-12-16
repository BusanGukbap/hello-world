#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N, K, i, res = 0, C[10];
	cin >> N >> K;
	for (i = 0; i < N; i++)
		cin >> C[i];
	while (--i > -1) {
		while (K >= C[i]) {
			K -= C[i];
			res++;
		}
	}
	cout << res;

	return 0;
}