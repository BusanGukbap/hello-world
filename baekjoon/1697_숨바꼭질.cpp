#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, K;
bool Visit[200000];

int bfs() {
	queue<pair<int, int>> Q;
	int res = 0;
	Q.push({ N, 0 });
	Visit[N] = true;

	while (!Q.empty()) {
		int now = Q.front().first;
		int depth = Q.front().second;
		Q.pop();

		if (now == K) {
			res = depth;
			break;
		}

		if (!Visit[now * 2] && now * 2 <= 100000) {
			Q.push({ now * 2, depth + 1 });
			Visit[now * 2] = true;
		}
		if (!Visit[now + 1] && now + 1 <= 100000) {
			Q.push({ now + 1, depth + 1 });
			Visit[now + 1] = true;
		}
		if (!Visit[now - 1] && now - 1 >= 0) {
			Q.push({ now - 1, depth + 1 });
			Visit[now - 1] = true;
		}
	}

	return res;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	cout << bfs();

	return 0;
}