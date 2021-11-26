#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct Fish {
	int y;
	int x;
	int dis;
} Fish;

int N; // 공간 크기
int input[30][30]; // 입력
int distance; // 거리 최소값
vector<pair<int, int>> fish_size[7]; // 물고기 크기마다 위치
bool Visit[30][30]; // 물고기 방문했는가?
queue<pair<pair<int, int>, pair<int, int>>> Q; // {{상어 위치}, {사이즈, 먹은 물고기 수} }
int total_time;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool range_in(int y, int x) {
	return (y >= 0 && x >= 0 && x < N && y < N);
}

int bfs(int shark_y, int shark_x, int fish_y, int fish_x, int shark_size) {
	bool visit_check[30][30];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit_check[i][j] = false;
	}

	int data = 401;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {shark_y, shark_x}, 0 });
	visit_check[shark_y][shark_x] = true;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (y == fish_y && x == fish_x) {
			data = cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (range_in(ny, nx) && input[ny][nx] <= shark_size && !visit_check[ny][nx]) {
				visit_check[ny][nx] = true;
				q.push({ {ny, nx}, cnt + 1 });
			}
		}
	}

	return data;
}

Fish find_fish(int shark_size, int a, int b) {
	Fish temp;
	temp.y = -1;
	temp.x = -1;
	temp.dis = 400;
	int return_y = -1, return_x = -1; // 벡터 삭제용

	for (int i = 1; i < shark_size; i++) {
		if (i > 6)
			break;
		for (int j = 0; j < fish_size[i].size(); j++) {
			int y = fish_size[i][j].first;
			int x = fish_size[i][j].second;
			int far = bfs(a, b, y, x, shark_size);

			if (!Visit[y][x]) {
				// 거리 단축 됐을 때
				if (temp.dis > far) {
					temp.dis = far;
					temp.y = y;
					temp.x = x;
					return_y = i;
					return_x = j;
				}
				// 거리는 같지만
				else if (temp.dis == far) {
					// 더 위에 있을 때
					if (y < temp.y) {
						temp.y = y;
						temp.x = x;
						return_y = i;
						return_x = j;
					}
					// 높이는 같지만 더 왼쪽에 있을 때
					else if (y == temp.y) {
						if (x < temp.x) {
							temp.x = x;
							return_y = i;
							return_x = j;
						}
					}
				}
			}
		}
	}

	Visit[temp.y][temp.x] = true;
	if (return_y != -1 && return_x != -1)
		fish_size[return_y].erase(fish_size[return_y].begin() + return_x);

	return temp;
}

void solution() {
	int cnt = 0;
	while (!Q.empty()) {
		int y = Q.front().first.first;
		int x = Q.front().first.second;
		int shark_size = Q.front().second.first;
		int fish_eaten = Q.front().second.second;
		Q.pop();

		Fish temp = find_fish(shark_size, y, x);
		if (temp.y == -1 && temp.x == -1)
			break;

		total_time += temp.dis;
		fish_eaten++;
		if (fish_eaten == shark_size) {
			shark_size++;
			fish_eaten = 0;
		}
		Q.push({ {temp.y, temp.x}, {shark_size, fish_eaten} });
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//ifstream fin;
	//fin.open("input.txt");

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 9) {
				Q.push({ {i, j}, {2, 0} });
				input[i][j] = 0;
			}
			else
				fish_size[input[i][j]].push_back({ i, j });
		}
	}

	solution();

	cout << total_time;

	return 0;
}