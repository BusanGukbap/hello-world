#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, H, W;
string input[10];
char Original[101];

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < H; j++) {
			if (Original[i] != '?')
				break;

			for (int k = 0; k < W; k++) {
				if (Original[i] == '?' && input[j][i * W + k] != '?') {
					Original[i] = input[j][i * W + k];
					break;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> H >> W;

	for (int i = 0; i < H; i++)
		cin >> input[i];
	for (int i = 0; i < N; i++) {
		Original[i] = '?';
	}

	func();

	for (int i = 0; i < N; i++)
		cout << Original[i];

	return 0;
}