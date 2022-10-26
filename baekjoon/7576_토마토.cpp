#include <bits/stdc++.h>

using namespace std;

int N, M;
int box[1001][1001];
int unripe_tomato;
queue <pair<int, int>> tomato;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			cin >> box[i][j];
			if (box[i][j] == 1)
				tomato.push({ i, j });
			else if (box[i][j] == 0)
				unripe_tomato++;
		}
	}
}

bool out_of_bound(int x, int y) {
	if (x < 0 || y < 0 || y >= M || x >= N)
		return true;
	return false;
}

void bfs() {
	while (!tomato.empty()) {
		int x = tomato.front().first;
		int y = tomato.front().second;
		tomato.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (!out_of_bound(nx, ny)) {
				if (box[nx][ny] == 0) {
					tomato.push({ nx, ny });
					box[nx][ny] = box[x][y] + 1;
				}
			}
		}
	}
}

int solution() {
	int ans = 0;
	
	input();

	// 익을 토마토가 없음
	if (unripe_tomato == 0) {
		return 0;
	}
	
	// bfs탐색으로 박스에 숫자 채우기
	bfs();

	// 끝나고 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				return -1;
			}
			if (box[i][j] > ans)
				ans = box[i][j];
		}
	}

	return ans-1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << solution();

	return 0;
}