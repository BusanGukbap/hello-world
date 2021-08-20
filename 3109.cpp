#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int R, C, res;
int drow[] = { -1, 0, 1 };
char board[100000][500];
bool finish;

void func(int row, int col) {
	int temp_row, temp_col;
	board[row][col] = 'P';
	for (int i = 0; i < 3; i++) {
		temp_row = row + drow[i];
		temp_col = col + 1;
		
		// 행 범위 확인 && 빈칸일때
		if (temp_row < R && temp_row >= 0 && board[temp_row][temp_col] == '.') {
			// 파이프끼리 크로스 확인
			if (i == 0 && board[row - 1][col] == 'P' && board[row][col + 1] == 'P')
				continue;
			// 마지막 열일때
			if (temp_col == C - 1) {
				finish = true;
				res++;
				board[temp_row][temp_col] = 'P';
				return;
			}
			func(temp_row, temp_col);
		}

		if (finish) {
			return;
		}
	}
	//board[row][col] = '.';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < R; i++) {
		finish = false;
		func(i, 0);
	}

	cout << res;

	return 0;
}