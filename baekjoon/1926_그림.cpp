#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[500][500];

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool Visit[500][500];

vector<int> picture;

bool out_of_bound(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)
		return true;
	return false;
}

void bfs(int b, int a) {
	queue<pair<int, int>> q;
	q.push({ b, a });

	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!out_of_bound(ny, nx) && board[ny][nx] == 1 && Visit[ny][nx] == false) {
				Visit[ny][nx] = true;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}

	picture.push_back(cnt);
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && Visit[i][j] == false) {
				Visit[i][j] = true;
				bfs(i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			Visit[i][j] = false;
		}
	}

	func();
	picture.push_back(0);

	cout << picture.size()-1 << '\n';
	sort(picture.begin(), picture.end());
	cout << picture[picture.size() - 1];

	return 0;
}