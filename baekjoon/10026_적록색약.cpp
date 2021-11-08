#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
string board[101];
bool Visit[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Visit[i][j] = false;
	}
}

bool range_in(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

bool same_color(int x, int y, int nx, int ny, bool normal) {
	if (board[y][x] == board[ny][nx])
		return true;
	if (!normal) {
		if (board[y][x] != 'B' && board[ny][nx] != 'B')
			return true;
	}
	return false;
}

void Normal_DFS(int y, int x) {
	Visit[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!Visit[ny][nx] && range_in(nx, ny) && same_color(x, y, nx, ny, true)) {
			Normal_DFS(ny, nx);
		}
	}
}

void Red_Green_DFS(int y, int x) {
	Visit[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!Visit[ny][nx] && range_in(nx, ny) && same_color(x, y, nx, ny, false)) {
			Red_Green_DFS(ny, nx);
		}
	}
}

int Normal() {
	clear();
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visit[i][j]) {
				idx++;
				Normal_DFS(i, j);
			}
		}
	}

	return idx;
}

int Red_Green() {
	int idx = 0;
	clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visit[i][j]) {
				idx++;
				Red_Green_DFS(i, j);
			}
		}
	}

	return idx;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	cout << Normal() << " " << Red_Green() << '\n';

	return 0;
}