#define _CRT_SECUER_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 50
int N, M, result;
int lab[MAX][MAX];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
bool Visit[10];
int virus_place;
vector<pair<int, int>> Virus;

bool range_in(int y, int x) {
	return (y >= 0 && x >= 0 && x < N&& y < N);
}

bool not_virus_place(int y, int x) {
	bool same = false;
	for (int i = 0; i < Virus.size(); i++) {
		int b = Virus[i].first;
		int a = Virus[i].second;
		if (y == b && x == a) {
			same = true;
			break;
		}
	}
	return same;
}

void boom() {
	queue<pair<int, int>> Q;
	int save_file[50][50];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			save_file[i][j] = lab[i][j];
			if (save_file[i][j] == 3) {
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if ((save_file[ny][nx] == 0 || save_file[ny][nx] == 2) && range_in(ny, nx)) {
				save_file[ny][nx] = save_file[y][x] + 1;
				Q.push({ ny, nx });
			}
		}
	}

	int cnt = 0;
	bool all_kill = true;
	for (int i = 0; i < N; i++) {
		if (all_kill == false)
			break;
		for (int j = 0; j < N; j++) {
			if (all_kill == false)
				break;
			if (not_virus_place(i, j))
				continue;
			if (save_file[i][j] == 0 || save_file[i][j] == 2)
				all_kill = false;
		}
	}


	for (int i = 0; i < Virus.size(); i++) {
		int a = Virus[i].second;
		int b = Virus[i].first;
		save_file[b][a] = -1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cnt < save_file[i][j] && save_file[i][j] >= 3)
				cnt = save_file[i][j];
		}
	}


	if (all_kill == false)
		return;
	if (cnt == 0)
		result = cnt;
	else
		cnt -= 3;
	if (cnt < result)
		result = cnt;

}

void choose_place(int cnt, int idx) {
	if (cnt == M) {
		boom();
		return;
	}

	for (int i = idx; i < virus_place; i++) {
		if (!Visit[i]) {
			Visit[i] = true;
			int y = Virus[i].first;
			int x = Virus[i].second;
			lab[y][x] = 3;
			choose_place(cnt + 1, i + 1);
			lab[y][x] = 2;
			Visit[i] = false;
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) {
				virus_place++;
				Virus.push_back({ i, j });
			}
		}
	}
	result = 50 * 50;
	choose_place(0, 0);

	if (result == 50 * 50)
		cout << -1;
	else
		cout << result;

	return 0;
}