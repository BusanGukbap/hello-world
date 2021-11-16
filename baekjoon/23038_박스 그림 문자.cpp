#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
string box_drawing_charater[902];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < 3 * N; i++) {
		cin >> box_drawing_charater[i];
	}
}

void output() {
	for (int i = 0; i < 3 * N; i++) {
		cout << box_drawing_charater[i];
		cout << '\n';
	}
}

void draw_puzzle() {
	for (int i = 1; i < 3 * N; i += 3) {
		for (int j = 1; j < 3 * M; j += 3) {
			if (box_drawing_charater[i][j] == '#') {
				continue;
			}
			box_drawing_charater[i][j] = '#';
			for (int dir = 0; dir < 4; dir++) {
				int side_y = i + dy[dir] * 2;
				int side_x = j + dx[dir] * 2;
				if (side_x < 0 || side_y < 0 || side_x >= 3 * M || side_y >= 3 * N) {
					continue;
				}
				if (box_drawing_charater[side_y][side_x] == '#')
					box_drawing_charater[i + dy[dir]][j + dx[dir]] = '#';
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	draw_puzzle();
	output();


	return 0;
}