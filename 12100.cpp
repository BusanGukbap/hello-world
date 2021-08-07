#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int board[21][21];
int result;

void print_board(int index, int dir) {
	cout << index << " " << dir << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int same_check(int save[][21]) {
	int cnt1 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == save[i][j])
				cnt1++;
		}
	}
	if (cnt1 != N*N)
		return 0;
	else
		return 1;
}

void find_biggest_number() {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (board[i][j] > temp)
				temp = board[i][j];
	}

	if (result < temp) {
		result = temp;
	}
}

void save_loard(int save[][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = save[i][j];
		}
	}
}

void dir_left() {
	int temp;
	for (int i = 0; i < N; i++) {
		// 숫자합치기
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				int a = j;
				j++;
				while (j < N) {
					if (board[i][a] == board[i][j]) {
						board[i][a] *= 2;
						board[i][j] = 0;
						break;
					}
					else if (board[i][a] != board[i][j] && board[i][j] > 0) {
						j--;
						break;
					}
					else
						j++;
				}
			}
		}

		//숫자 옮기기
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				temp = j-1;
				while (board[i][temp] == 0 && temp >= 0) {
					board[i][temp] = board[i][temp+1];
					board[i][temp + 1] = 0;
					temp--;
				}
			}
		}
	}
}

void dir_up() {
	int temp;
	for (int i = 0; i < N; i++) {
		// 숫자합치기
		for (int j = 0; j < N; j++) {
			if (board[j][i] != 0) {
				int a = j;
				j++;
				while (j < N) {
					if (board[a][i] == board[j][i]) {
						board[a][i] *= 2;
						board[j][i] = 0;
						break;
					}
					else if (board[a][i] != board[j][i] && board[j][i] > 0) {
						j--;
						break;
					}
					else
						j++;
				}
			}
		}

		//숫자 옮기기
		for (int j = 0; j < N; j++) {
			if (board[j][i] != 0) {
				temp = j - 1;
				while (board[temp][i] == 0 && temp >= 0) {
					board[temp][i] = board[temp+1][i];
					board[temp+1][i] = 0;
					temp--;
				}
			}
		}
	}
}

void dir_right() {
	int temp;
	for (int i = 0; i < N; i++) {
		// 숫자합치기
		for (int j = N-1; j >= 0; j--) {
			if (board[i][j] != 0) {
				int a = j;
				j--;
				while (j >= 0) {
					if (board[i][a] == board[i][j]) {
						board[i][a] *= 2;
						board[i][j] = 0;
						break;
					}
					else if (board[i][a] != board[i][j] && board[i][j] > 0) {
						j++;
						break;
					}
					else
						j--;
				}
			}
		}

		//숫자 옮기기
		for (int j = N-1; j >= 0; j--) {
			if (board[i][j] != 0) {
				temp = j + 1;
				while (board[i][temp] == 0 && temp <= N-1) {
					board[i][temp] = board[i][temp - 1];
					board[i][temp - 1] = 0;
					temp++;
				}
			}
		}
	}
}

void dir_down() {
	int temp;
	for (int i = 0; i < N; i++) {
		// 숫자합치기
		for (int j = N-1; j >= 0; j--) {
			if (board[j][i] != 0) {
				int a = j;
				j--;
				while (j >= 0) {
					if (board[a][i] == board[j][i]) {
						board[a][i] *= 2;
						board[j][i] = 0;
						break;
					}
					else if (board[a][i] != board[j][i] && board[j][i] > 0) {
						j++;
						break;
					}
					else
						j--;
				}
			}
		}

		//숫자 옮기기
		for (int j = N-1; j >= 0; j--) {
			if (board[j][i] != 0) {
				temp = j + 1;
				while (board[temp][i] == 0 && temp <= N-1) {
					board[temp][i] = board[temp-1][i];
					board[temp - 1][i] = 0;
					temp++;
				}
			}
		}
	}
}

void func(int index) {
	if (index >= 5) {
		find_biggest_number();
		return;
	}

	int temp[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = board[i][j];
	}
	
	int cnt = 0;
	dir_left();
//	print_board(index, 1);
	if (!same_check(temp))
		func(index + 1);
	else
		cnt++;
	save_loard(temp);
	
	dir_up();
//	print_board(index, 2);
	if (!same_check(temp))
		func(index + 1);
	else
		cnt++;
	save_loard(temp);
	
	dir_right();
//	print_board(index, 3);
	if (!same_check(temp))
		func(index + 1);
	else
		cnt++;
	save_loard(temp);

	dir_down();
//	print_board(index, 4);
	if (!same_check(temp))
		func(index + 1);
	else
		cnt++;
	save_loard(temp);
	
	if (cnt == 4) {
		find_biggest_number();
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	func(0);

	cout << result;

	return 0;
}