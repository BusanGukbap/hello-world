#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int R, C;
int maxx;
bool Visit[26];
bool board_visit[20][20];
string board[20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool range_in(int x, int y) {
	return (x >= 0 && y >= 0 && x < C && y < R);
}

void dfs(int y, int x, int cnt) {
	Visit[board[y][x] - 'A'] = true;
	board_visit[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (range_in(nx, ny) && !Visit[board[ny][nx] - 'A'] && !board_visit[ny][nx]) {
			dfs(ny, nx, cnt+1);
		}
	}
	if (cnt > maxx)
		maxx = cnt;
	board_visit[y][x] = false;
	Visit[board[y][x] - 'A'] = false;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];

	dfs(0, 0, 1);

	cout << maxx;

	return 0;
}