#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int X;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> X;
	int cnt = 0;
	for (int i = 1; i <= 64; i = i<<1) {
		if (X&i)
			cnt++;
	}
	cout << cnt;

	return 0;
}