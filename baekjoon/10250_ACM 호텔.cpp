#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int T, H, W, N;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> H >> W >> N;
		int Y = N % H;
		if (Y == 0)
			Y = H;
		int X = N / H + 1;
		if (Y == H)
			X--;
		cout << Y * 100 + X << '\n';
	}

	return 0;
}