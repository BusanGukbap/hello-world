#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

#define MAX 50
int N, M;
int minn = -1;
string mazz[MAX];
int Visit[MAX][MAX][1<<6];
// FEDCBA 순서로 6비트 크기

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> mazz[i];
	}
}

bool range_in(int y, int x) {
	return (x >= 0 && y >= 0 && x < M && y < N);
}

void BFS() {
	queue <pair<pair<int, int>, pair<int, int>>> Q;
	int start_y = -1, start_x = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mazz[i][j] == '0') {
				start_y = i;
				start_x = j;
				break;
			}
		}
		if (start_y != -1)
			break;
	}

	Q.push({ {start_y, start_x}, {0, 0} });
	
	while (!Q.empty()) {
		int y = Q.front().first.first;
		int x = Q.front().first.second;
		int cnt = Q.front().second.first;
		int key = Q.front().second.second;
		Q.pop();
		Visit[y][x][key] = true;

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (range_in(ny, nx) && !Visit[ny][nx][key]) {
				// 벽
				if (mazz[ny][nx] == '#') {
					continue;
				}
				// 탈출
				else if (mazz[ny][nx] == '1') {
					if (minn == -1 || minn > cnt+1)
						minn = cnt+1;
					continue;
				}
				// 그냥 길
				else if (mazz[ny][nx] == '.' || mazz[ny][nx] == '0') {
					Visit[ny][nx][key] = true;
					Q.push({ {ny, nx}, {cnt + 1, key} });
				}
				// 열쇠 주움
				else if (mazz[ny][nx] >= 'a' && mazz[ny][nx] <= 'f'){
					Visit[ny][nx][key] = true;
					int nkey = key | (1 << (mazz[ny][nx] - 'a'));
					Q.push({ {ny, nx}, {cnt + 1, nkey} });
				}
				// 문
				else if (mazz[ny][nx] >= 'A' && mazz[ny][nx] <= 'F') {
					Visit[ny][nx][key] = true;
					int door = 1 << (mazz[ny][nx] - 'A');
					if (key & door) {
						Q.push({ {ny, nx}, {cnt + 1, key} });
					}
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	BFS();
	cout << minn;

	return 0;
}