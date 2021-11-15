#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
int lab[8][8];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int result;

bool range_in(int y, int x) {
	return (y >= 0 && x >= 0 && x < M && y < N);
}

void virus() {
	int save_file[8][8];
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			save_file[i][j] = lab[i][j];
			if (save_file[i][j] == 2)
				Q.push({ i, j });
		}
	}

	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (range_in(ny, nx) && save_file[ny][nx] == 0) {
				Q.push({ ny, nx });
				save_file[ny][nx] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (save_file[i][j] == 0)
				cnt++;
		}
	}

	if (result < cnt)
		result = cnt;
}

void build_wall(int idx) {
	if (idx == 3) {
		virus();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				build_wall(idx + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> lab[i][j];
	}

	build_wall(0);

	cout << result;

	return 0;
}