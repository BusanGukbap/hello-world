#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define MAX 10
using namespace std;

int N;
bool visited1[MAX*2]; // ↘방향 row-col+N
bool visited2[MAX*2]; // ↙방향 row+col
int bishop[2];
int board[MAX][MAX];
// 1->놓을 수 있음, 0->놓을 수 없음

void func(int x, int y, int color, int cnt) {
	if (y >= N) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}

	if (x >= N) {
		if (cnt > bishop[color])
			bishop[color] = cnt;
		return;
	}

	if (board[x][y] && !visited1[x - y + N] && !visited2[x + y]) {
		visited1[x - y + N] = visited2[x + y] = 1;
		func(x, y + 2, color, cnt + 1);
		visited1[x - y + N] = visited2[x + y] = 0;
	}

	func(x, y + 2, color, cnt);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	func(0, 0, 0, 0);
	func(0, 1, 1, 0);

	cout << bishop[0] + bishop[1];
	
	return 0;
}