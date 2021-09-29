#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

typedef struct direction {
	int x;
	int y;
} Dir;

//              가로   대각선   세로
Dir dir[3] = { {0, 1}, {1, 1}, {1, 0} };

int result;
int N;
int map[17][17];



// pipe_dir 0->가로, 1->대각선, 2->세로
void func(int x, int y, int pipe_dir) {
	if (x == N - 1 && y == N - 1) {
		result++;
		return;
	}

	int x_temp, y_temp;

	for (int i = 0; i < 3; i++) {
		if ((i == 0 && pipe_dir == 2) || (i == 2 && pipe_dir == 0)) {
			continue;
		}
		
		x_temp = x + dir[i].x;
		y_temp = y + dir[i].y;

		// 범위초과
		if (x_temp >= N || y_temp >= N) {
			continue;
		}
		
		// 벽 확인
		else if (map[x_temp][y_temp] == 1) {
			continue;
		}
		
		// 대각선 벽 확인
		else if (i == 1 && (map[x][y + 1] == 1 || map[x + 1][y] == 1)) {
			continue;
		}
	
		else
			func(x_temp, y_temp, i);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	result = 0;
	func(0, 1, 0);


	cout << result;

	return 0;
}
