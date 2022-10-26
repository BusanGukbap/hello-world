#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N, K, i, res = 0, Coin[10];

	cin >> N >> K;

	for (i = 0; i < N; i++)
		cin >> Coin[i];

	while (--i > -1) {
		while (K >= Coin[i]) {
			K -= Coin[i];
			res++;
		}
	}

	cout << res;

	return 0;
}