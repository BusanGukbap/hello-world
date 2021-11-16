#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
string mazz[50];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int Visit[50][50];

bool range_in(int y, int x) {
	return (y >= 0 && x >= 0 && x < N && y < N);
}

void bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Visit[i][j] = 50*50;
	}
	Visit[0][0] = 0;

	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		if (y == N - 1 && x == N - 1)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if (!range_in(ny, nx))
				continue;

			if (mazz[ny][nx] == '0') {
				if (Visit[ny][nx] > Visit[y][x] + 1) {
					Visit[ny][nx] = Visit[y][x] + 1;
					Q.push({ ny, nx });
				}
			}
			else if (mazz[ny][nx] == '1') {
				if (Visit[ny][nx] > Visit[y][x]) {
					Visit[ny][nx] = Visit[y][x];
					Q.push({ ny, nx });
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> mazz[i];
	}

	bfs();
	cout << Visit[N - 1][N - 1];

	return 0;
}