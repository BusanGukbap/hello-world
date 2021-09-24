// sw expert academy
// D4 부서진타일

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;

char board[50][50];
bool temp;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int TC;
	cin >> TC;
	
	for (int test_case = 1; test_case <= TC; test_case++) {
		temp = true;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == '#') {
					if (i == N - 1 || j == M - 1) {
						temp = false;
						break;
					}
					else if (board[i + 1][j] == '#' && board[i][j + 1] == '#' && board[i + 1][j + 1] == '#') {
						board[i][j] = '.';
						board[i + 1][j] = '.';
						board[i + 1][j + 1] = '.';
						board[i][j + 1] = '.';
					}
					else {
						temp = false;
						break;
					}
				}
			}
		}

		

		cout << "#" << test_case << " ";
		if (temp == false) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}