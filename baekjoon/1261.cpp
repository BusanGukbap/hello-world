#define _CRT_SECUER_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000

int N, M;
int maze[100][100];
int ans[100][100];
queue<pair<int, int>> pq;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dijkstra(int x, int y) {
	ans[x][y] = 0;
	pq.push({ x,y });
	
	while (!pq.empty()) {
		int current_x = pq.front().first;
		int current_y = pq.front().second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
				continue;

			if (maze[next_x][next_y] == 1 && ans[next_x][next_y] > ans[current_x][current_y] + 1) {
				ans[next_x][next_y] = ans[current_x][current_y] + 1;
				pq.push({ next_x, next_y });
			}
			else if (maze[next_x][next_y] == 0 && ans[next_x][next_y] > ans[current_x][current_y]){
				ans[next_x][next_y] = ans[current_x][current_y];
				pq.push({ next_x, next_y });
			}
 		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			maze[i][j] = s[j] - '0';
			ans[i][j] = INF;
		}
	}

	dijkstra(0, 0);
	cout << ans[N - 1][M - 1];

	return 0;
}