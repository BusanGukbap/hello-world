#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;
int Visit[101] = { 99999};

void BFS() {
	//        ÁÂÇ¥, ±¼¸°È½¼ö
	queue<pair<int, int>> Q;
	Q.push({ 1, 0 });
	while (!Q.empty()) {
		int idx = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		for (int dice = 1; dice <= 6; dice++) {
			int nidx = idx + dice;
			for (int i = 0; i < N; i++) {
				if (ladder[i].first == nidx) {
					nidx = ladder[i].second;
					break;
				}
			}
			for (int i = 0; i < M; i++) {
				if (snake[i].first == nidx) {
					nidx = snake[i].second;
					break;
				}
			}

			if (Visit[nidx] > cnt + 1) {
				Visit[nidx] = cnt + 1;
				if (nidx == 100) {
					break;
				}
				else
					Q.push({ nidx, cnt + 1 });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		ladder.push_back({ a, b });
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		snake.push_back({ a,b });
	}
	
	for (int i = 1; i <= 100; i++) {
		Visit[i] = 99999;
	}
	BFS();

	cout << Visit[100];

	return 0;
}