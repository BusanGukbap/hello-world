#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, r, c;
int res;

void where_are_you(int len) {
	if (len == 1) {
		return;
	}
	if (r >= len / 2) {
		res += len * len / 2;
		r -= len / 2;
	}
	if (c >= len / 2) {
		res += len * len / 4;
		c -= len / 2;
	}
	where_are_you(len / 2);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	int len = pow(2, N);

	where_are_you(len);
	
	cout << res;

	return 0;
}