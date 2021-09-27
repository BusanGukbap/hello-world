#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int M, N;

int tomato;
int box[1000][1000];
queue<int> qx;
queue<int> qy;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void change(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		if (x + dx[dir] >= 0 && x + dx[dir] < N && y + dy[dir] >= 0 && y + dy[dir] < M && box[x + dx[dir]][y + dy[dir]] == 0) {
			box[x + dx[dir]][y + dy[dir]] = box[x][y] + 1;
			qx.push(x + dx[dir]);
			qy.push(y + dy[dir]);
			tomato--;
		}
	}
}

int func() {
	int maxx = 0;

	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		change(x, y);
		qx.pop();
		qy.pop();
	}

	if (tomato != 0)
		return -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] > maxx)
				maxx = box[i][j];
		}
	}

	return maxx-1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0)
				tomato++;
			if (box[i][j] == 1) {
				qx.push(i);
				qy.push(j);
			}
		}
	}

	if (tomato == 0)
		cout << 0;
	else
		cout << func();

	return 0;
}