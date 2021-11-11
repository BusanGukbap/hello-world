#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[25 * 25];
int Village[26][26];
bool Visit[26][26];
int idx;
int cnt;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool range_in(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

void dfs(int x, int y) {
	idx++;
	Visit[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (Village[ny][nx] && !Visit[ny][nx] && range_in(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {
			Village[i][j] = temp[j] - '0';
		}
	}

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Village[i][j] && !Visit[i][j]) {
				idx = 0;
				dfs(j, i);
				arr[cnt++] = idx;
			}
		}
	}

	cout << cnt << '\n';
	sort(arr, arr + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}