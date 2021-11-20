#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

int sudoku[9][9];
bool col_check[9][10];
bool row_check[9][10];
bool square_check[9][10];

bool overlap_check(int y, int x, int data) {
	bool overlap = false;
	if (col_check[y][data])
		overlap = true;
	else if (row_check[x][data])
		overlap = true;
	else if (square_check[(y / 3) * 3 + (x / 3)][data])
		overlap = true;
	return overlap;
}

void print_sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << '\n';
	}
}

void backtracking(int idx) {
	int i = idx / 9;
	int j = idx % 9;

	if (idx == 81) {
		print_sudoku();
		exit(0);
	}

	if (sudoku[i][j] == 0) {
		for (int data = 1; data <= 9; data++) {
			if (!overlap_check(i, j, data)) {
				sudoku[i][j] = data;
				col_check[i][data] = true;
				row_check[j][data] = true;
				square_check[(i / 3) * 3 + (j / 3)][data] = true;
				backtracking(idx+1);
				sudoku[i][j] = 0;
				col_check[i][data] = false;
				row_check[j][data] = false;
				square_check[(i / 3) * 3 + (j / 3)][data] = false;
			}
		}
	}
	else
		backtracking(idx + 1);

}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0) {
				col_check[i][sudoku[i][j]] = true;
				row_check[j][sudoku[i][j]] = true;
				square_check[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}

	backtracking(0);

	return 0;
}