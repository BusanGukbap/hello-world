#include<bits/stdc++.h>

using namespace std;

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
bool Visit[300][300];
int L;

bool OutOfBound(int x, int y) {
	if (x < 0 || y < 0 || x >= L || y >= L)
		return true;
	return false;
}

void solve() {
	queue<pair<pair<int, int>, int>> Q;
	int Sx, Sy, Ax, Ay;
	
	cin >> L;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++)
			Visit[i][j] = false;
	}
	cin >> Sx >> Sy;
	cin >> Ax >> Ay;
	Q.push({ {Sx, Sy}, 0 });
	Visit[Sx][Sy] = true;

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int index = Q.front().second;
		Q.pop();

		if (x == Ax && y == Ay) {
			cout << index << '\n';
			return;
		}

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (!OutOfBound(nx, ny) && Visit[nx][ny] == false) {
				Q.push({ {nx, ny}, index + 1 });
				Visit[nx][ny] = true;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}