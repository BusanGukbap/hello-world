#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
bool Visit[51][51];
string input[51];

void bfs(int x, int y) {
	Visit[y][x] = true;
	if (input[y][x] == '-' && (x + 1 < M) && input[y][x + 1] == '-')
		bfs(x + 1, y);
	else if (input[y][x] == '|' && (y + 1 < N) && input[y + 1][x] == '|')
		bfs(x, y + 1);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!Visit[i][j]) {
				cnt++;
				bfs(j, i);
			}
		}
	}

	cout << cnt;

	return 0;
}