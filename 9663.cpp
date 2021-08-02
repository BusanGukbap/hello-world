#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int result;
int board[16][16];

void check_in(int x, int y) {
	for (int i = 1; i <= N; i++) {
		board[x][i] += 1;
		board[i][y] += 1;
		if ((x - i >= 1) && (y - i >= 1)) {
			board[x - i][y - i] += 1;
		}
		if ((x + i <= N) && (y + i <= N)) {
			board[x + i][y + i] += 1;
		}
		if ((x - i >= 1) && (y + i <= N)) {
			board[x - i][y + i] += 1;
		}
		if ((x + i <= N) && (y - i >= 1)) {
			board[x + i][y - i] += 1;
		}
	}
}

void check_out(int x, int y) {
	for (int i = 1; i <= N; i++) {
		board[x][i] -= 1;
		board[i][y] -= 1;
		if ((x - i >= 1) && (y - i >= 1)) {
			board[x - i][y - i] -= 1;
		}
		if ((x + i <= N) && (y + i <= N)) {
			board[x + i][y + i] -= 1;
		}
		if ((x - i >= 1) && (y + i <= N)) {
			board[x - i][y + i] -= 1;
		}
		if ((x + i <= N) && (y - i >= 1)) {
			board[x + i][y - i] -= 1;
		}
	}
}

void queen(int col) {
	if (col > N) {
		result++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (board[i][col] == 0) {
			check_in(i, col);
			queen(col + 1);
			check_out(i, col);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	result = 0;
	cin >> N;
	queen(1);

	cout << result;
	
	return 0;
}