#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool Visit[101][101];
bool board[101][101];
int maxx, Index;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool range_in(int x, int y) {
	return (x > 0 && y > 0 && x <= M && y <= N);
}

void dfs(int y, int x) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (range_in(nx, ny) && !Visit[ny][nx] && board[ny][nx]) {
			Index++;
			Visit[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		board[r][c] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Visit[i][j] = true;
			if (board[i][j]) {
				Index = 1;
				dfs(i, j);
				if (Index > maxx)
					maxx = Index;
			}
		}
	}

	cout << maxx;

	return 0;
}