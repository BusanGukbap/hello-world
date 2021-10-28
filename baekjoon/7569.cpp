#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int M, N, H;

int tomato;
int box[100][100][100];
queue<int> qx;
queue<int> qy;
queue<int> qz;
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

void change(int x, int y, int z) {
	for (int dir = 0; dir < 6; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int nz = z + dz[dir];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && box[nx][ny][nz] == 0) {
			box[nx][ny][nz] = box[x][y][z] + 1;
			qx.push(nx);
			qy.push(ny);
			qz.push(nz);
			tomato--;
		}
	}
}

int func() {
	int maxx = 0;

	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		int z = qz.front();
		change(x, y, z);
		qx.pop();
		qy.pop();
		qz.pop();
	}

	if (tomato != 0)
		return -1;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][k] > maxx)
					maxx = box[i][j][k];
			}
		}
	}

	return maxx - 1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 0)
					tomato++;
				if (box[i][j][k] == 1) {
					qx.push(i);
					qy.push(j);
					qz.push(k);
				}
			}
		}
	}

	if (tomato == 0)
		cout << 0;
	else
		cout << func();

	return 0;
}