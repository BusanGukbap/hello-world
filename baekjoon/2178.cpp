#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int N, M;
int res;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void DFS(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, 1));
	visited[x][y] = 1;

	while (!q.empty()) {
		int cur_x = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		if (cur_x == N - 1 && cur_y == M - 1) {
			if (res > cnt)
				res = cnt;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];

				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
					continue;

				if (maze[next_x][next_y] && visited[next_x][next_y] == 0) {
					q.push(make_tuple(next_x, next_y, cnt + 1));
					visited[next_x][next_y] = 1;
				}
			}
		}
	}



	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++)
			maze[i][j] = str[j] - '0';
	}

	res = N * M;

	DFS(0, 0);

	cout << res;

	return 0;
}