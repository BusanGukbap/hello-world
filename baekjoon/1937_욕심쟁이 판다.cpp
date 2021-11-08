#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int forest[501][501];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int DP[501][501];

bool range_in(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

int Bigger(int a, int b) {
	return a > b ? a : b;
}

int DFS(int x, int y) {
	if (DP[x][y])
		return DP[x][y];
	DP[x][y] = 1;

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (range_in(nx, ny) && forest[x][y] < forest[nx][ny]) {
			DP[x][y] = Bigger(DP[x][y], 1 + DFS(nx, ny));
		}
	}
	return DP[x][y];
}

void solution() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = Bigger(ans, DFS(i, j));
		}
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> forest[i][j];
	}

	solution();

	return 0;
}