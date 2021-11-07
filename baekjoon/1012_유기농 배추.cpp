#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int T, N, M, K;
bool Visit[51][51];
bool field[51][51];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Visit[i][j] = false;
			field[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!Visit[ny][nx] && field[ny][nx]) {
			Visit[ny][nx] = true;
			dfs(nx, ny);
		}
	}
}

void solution() {
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] && !Visit[i][j]) {
				idx++;
				Visit[i][j] = true;
				dfs(j, i);
			}
		}
	}
	cout << idx << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		clear();
		cin >> M >> N >> K;
		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			field[y][x] = true;
		}
		solution();
	}

	return 0;
}