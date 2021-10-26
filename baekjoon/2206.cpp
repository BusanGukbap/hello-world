#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
// 길이면 0, 벽이면 1
int mapp[1000][1000];
//            X      Y   WALL : false일때 안부숨, true일때 부숨
bool visited[1000][1000][2];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool range_over(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&& y < M);
}

int bfs() {
	queue < pair< pair<int, int>, pair<int, int> > > q;
	q.push({ {0, 0, }, {0, 1} });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int broken = q.front().second.first;
		int cnt = q.front().second.second;

		q.pop();

		if (x == N - 1 && y == M - 1) {
			return cnt;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (range_over(nx, ny)) {
				// 벽이고, 부술수 있는 경우
				if (mapp[nx][ny] == 1 && broken == 0) {
					visited[nx][ny][broken + 1] = true;
					q.push({ {nx, ny}, {broken + 1, cnt + 1} });
				}

				// 길이고, 안가본 경우
				if (mapp[nx][ny] == 0 && visited[nx][ny][broken] == 0) {
					visited[nx][ny][broken] = true;
					q.push({ {nx, ny}, {broken, cnt + 1} });
				}
			}
		}

	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			mapp[i][j] = str[j] - '0';
		}
	}

	cout << bfs();

	return 0;
}