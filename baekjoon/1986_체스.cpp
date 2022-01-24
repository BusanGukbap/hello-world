#include <bits/stdc++.h>

using namespace std;

int N, M, Queen, Knight, Pawn;

char board[1001][1001];
queue <pair<int, int>> Q;
queue <pair<int, int>> K;
vector <pair<int, int>> K_dir;
vector <pair<int, int>> Q_dir;

void input() {
	int x, y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			board[i][j] = 'O';
		}
	}
	cin >> Queen;
	for (int i = 0; i < Queen; i++) {
		cin >> y >> x;
		board[y][x] = 'Q';
		Q.push({ y, x });
	}
	cin >> Knight;
	for (int i = 0; i < Knight; i++) {
		cin >> y >> x;
		board[y][x] = 'K';
		K.push({ y, x });
	}
	cin >> Pawn;
	for (int i = 0; i < Pawn; i++) {
		cin >> y >> x;
		board[y][x] = 'P';
	}

	K_dir.push_back({ -2, -1 }); K_dir.push_back({ -1, -2 });
	K_dir.push_back({ -2, 1 });  K_dir.push_back({ -1, 2 });
	K_dir.push_back({ 1, -2 });  K_dir.push_back({ 2, -1 });
	K_dir.push_back({ 1, 2 });   K_dir.push_back({ 2, 1 });
	Q_dir.push_back({ -1, -1 }); Q_dir.push_back({ -1, 0 });
	Q_dir.push_back({ -1, 1 });  Q_dir.push_back({ 0, 1 });
	Q_dir.push_back({ 1, 1 });   Q_dir.push_back({ 1, 0 });
	Q_dir.push_back({ 1, -1 });  Q_dir.push_back({ 0, -1 });
}

bool out_of_bound(int y, int x) {
	if (x < 0 || y < 0 || y > N || x > M)
		return true;
	return false;
}

void check_queen(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + Q_dir[i].first;
		int nx = x + Q_dir[i].second;

		while (!out_of_bound(ny, nx)) {
			if (board[ny][nx] == 'O' || board[ny][nx] == 'X') {
				board[ny][nx] = 'X';
				ny += Q_dir[i].first;
				nx += Q_dir[i].second;
			}
			else
				break;
		}
	}
}

void check_knight(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + K_dir[i].first;
		int nx = x + K_dir[i].second;

		if (!out_of_bound(ny, nx) && board[ny][nx] == 'O') {
			board[ny][nx] = 'X';
		}
	}
}

void solution() {
	int cnt = 0;
	while (!Q.empty()) {
		check_queen(Q.front().first, Q.front().second);
		Q.pop();
	}

	while (!K.empty()) {
		check_knight(K.front().first, K.front().second);
		K.pop();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 'O')
				cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}