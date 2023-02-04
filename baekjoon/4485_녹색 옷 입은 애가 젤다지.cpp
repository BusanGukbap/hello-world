#include <iostream>
#include <queue>

using namespace std;

// [y][x]
int N;
int inputData[126][126];
bool isvisit[126][126];
int temp[126][126];
int minn;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	temp[0][0] = inputData[0][0];

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == N - 1 && x == N - 1) {
			if (temp[y][x] < minn) {
				minn = temp[y][x];
		//		cout << minn << ' ';
			}
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= N || ny >= N || nx < 0 || ny < 0)
				continue;

			if (isvisit[ny][nx] == false) {
				temp[ny][nx] = temp[y][x] + inputData[ny][nx];
				isvisit[ny][nx] = true;
				q.push({ ny, nx });
			}
			else if (isvisit[ny][nx] == true && temp[ny][nx] > temp[y][x] + inputData[ny][nx]) {
				temp[ny][nx] = temp[y][x] + inputData[ny][nx];
				q.push({ ny, nx });
			}
		}
	}
}

void solution() {
	minn = 400000;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> inputData[i][j];
			isvisit[i][j] = false;
			temp[i][j] = 0;
		}
	}

	bfs();

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int tc = 1; ; tc++) {
		cin >> N;
		if (N == 0)
			break;
		
		solution();

		cout << "Problem " << tc << ": " << minn << '\n';
	}

	return 0;
}