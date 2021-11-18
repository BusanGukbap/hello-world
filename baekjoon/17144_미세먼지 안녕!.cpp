#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define MAX 50
int R, C, T;
int Room[MAX][MAX];
int total_dust;
vector<pair<int, int>> air_cleaner;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool range_in(int y, int x) {
	return (y >= 0 && x >= 0 && y < R && x < C);
}

void spread_dust() {
	queue<pair<int, int>> Q;
	int save_file[MAX][MAX];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			save_file[i][j] = Room[i][j];
			Q.push({ i, j });
		}
	}

	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		int dust = save_file[y][x] / 5;

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (range_in(ny, nx) && save_file[ny][nx] != -1) {
				Room[y][x] -= dust;
				Room[ny][nx] += dust;
			}
		}
	}
	/*cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << Room[i][j] << " ";
		}
		cout << '\n';
	}*/
}

void blow_wind() {
	int before_dust = 0;
	int black_hole_y = air_cleaner[0].first;
	int black_hole_x = air_cleaner[0].second;
	int air_y = black_hole_y;
	int air_x = black_hole_x;

	// ���κ� �ݽð����, ����û���� ���κп��� ����, Room[i][j]�� ��ǥ�� ���⸦ �ٲ���
	// ���������� ����
	for (int j = black_hole_x+1; j < C-1; j++) {
		int temp = Room[black_hole_y][j];
		Room[black_hole_y][j] = before_dust;
		before_dust = temp;
	}
	// ���� ����
	for (int i = black_hole_y; i > 0; i--) {
		int temp = Room[i][C - 1];
		Room[i][C - 1] = before_dust;
		before_dust = temp;
	}
	// �������� ����
	for (int j = C - 1; j > 0; j--) {
		int temp = Room[0][j];
		Room[0][j] = before_dust;
		before_dust = temp;
	}
	// �Ʒ��� ����
	for (int i = 0; i < black_hole_y; i++) {
		int temp = Room[i][0];
		Room[i][0] = before_dust;
		before_dust = temp;
	}
	// ����û������� ���������� ����, ���⸦ �ٲٴ� ���̹Ƿ� ����û���� ��ǥ�� ����X
	for (int j = 0; j < black_hole_x; j++) {
		int temp = Room[black_hole_y][j];
		Room[black_hole_y][j] = before_dust;
		before_dust = temp;
	}
	total_dust -= before_dust;

	black_hole_y = air_cleaner[1].first;
	black_hole_x = air_cleaner[0].second;
	before_dust = 0;
	// ����û���� �ؿ��κ�, �ð�������� ����
	// ���������� ����
	for (int j = black_hole_x + 1; j < C - 1; j++) {
		int temp = Room[black_hole_y][j];
		Room[black_hole_y][j] = before_dust;
		before_dust = temp;
	}
	// �Ʒ��� ����
	for (int i = black_hole_y; i < R - 1; i++) {
		int temp = Room[i][C - 1];
		Room[i][C - 1] = before_dust;
		before_dust = temp;
	}
	// �������� ����
	for (int j = C - 1; j > 0; j--) {
		int temp = Room[R-1][j];
		Room[R-1][j] = before_dust;
		before_dust = temp;
	}
	// ���ʷ� ����
	for (int i = R - 1; i > black_hole_y; i--) {
		int temp = Room[i][0];
		Room[i][0] = before_dust;
		before_dust = temp;
	}
	// ���������� ����
	for (int j = 0; j < black_hole_x; j++) {
		int temp = Room[black_hole_y][j];
		Room[black_hole_y][j] = before_dust;
		before_dust = temp;
	}
	total_dust -= before_dust;

	/*cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << Room[i][j] << " ";
		}
		cout << '\n';
	}*/
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Room[i][j];
			if (Room[i][j] > 0) {
				total_dust += Room[i][j];
			}
			if (Room[i][j] == -1) {
				air_cleaner.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < T; i++) {
		spread_dust();
		blow_wind();
	}

	cout << total_dust;

	return 0;
}