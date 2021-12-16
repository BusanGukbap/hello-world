#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, K, L;
int board[100][100];
// 0이면 Left, 1이면 Right
deque<pair<int, int>> snake;
queue<pair<int, char>> RL;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool range_out(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&& y < N);
}

int change_dir(int dir) {
	// 오른쪽으로 90도 회전
	if (RL.front().second == 'D') {
		dir = (dir + 1) % 4;
	}
	// 왼쪽으로 90도 회전
	else if (RL.front().second == 'L') {
		dir = (dir - 1) % 4;
		if (dir < 0)
			dir += 4;
	}
	return dir;
}

int func() {
	snake.push_back({ 0, 0 });
	board[0][0] = 2;
	int dir = 0;

	for (int time = 1; ; time++) {
		int tail_x = snake.front().first;
		int tail_y = snake.front().second;
		int head_x = snake.back().first + dx[dir];
		int head_y = snake.back().second + dy[dir];

		if (board[head_x][head_y] == 2 || !range_out(head_x, head_y)) {
			return time;
		}

		// 사과일때
		if (board[head_x][head_y] == 1) {
			board[head_x][head_y] = 2;
			snake.push_back({ head_x, head_y });
		}
		// 빈공간일때
		else if (board[head_x][head_y] == 0) {
			board[tail_x][tail_y] = 0;
			board[head_x][head_y] = 2;
			snake.pop_front();
			snake.push_back({ head_x, head_y });
		}

		if (!RL.empty() && RL.front().first == time) {
			dir = change_dir(dir);
			RL.pop();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y, z;
	char d;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> z >> d;
		RL.push({ z, d });
	}

	cout << func();

	return 0;
}