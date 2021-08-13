#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
char board[2200][2200];

void func(int x, int y, int len) {
	if (len == 1) {
		board[x][y] = '*';
		return;
	}

	int temp = len / 3;
	for (int i = x + temp; i < x + temp * 2; i++) {
		for (int j = y + temp; j < y + temp * 2; j++) {
			board[i][j] = ' ';
		}
	}

	func(x, y, temp);
	func(x, y + temp, temp);
	func(x, y + temp * 2, temp);
	func(x + temp, y, temp);
	func(x + temp, y + temp * 2, temp);
	func(x + temp * 2, y, temp);
	func(x + temp * 2, y + temp, temp);
	func(x + temp * 2, y + temp * 2, temp);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;


	func(1, 1, N);


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}