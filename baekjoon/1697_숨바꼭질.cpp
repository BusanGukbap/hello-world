#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, K;
bool Visit[200000];

void bfs() {
	queue <int> Q;
	queue <int> searching;
	int cnt = 0;
	bool Find = false;
	Q.push(N);
	Visit[N] = true;

	while (1) {
		while (!Q.empty()) {
			searching.push(Q.front());
			Q.pop();
		}

		while (!searching.empty()) {
			int now = searching.front();
			searching.pop();

			if (now == K) {
				Find = true;
				break;
			}

			if (now*2 <= 100000 && !Visit[now * 2]) {
				Q.push(now * 2);
				Visit[now * 2] = true;
			}
			if (now+1 <= 100000 && !Visit[now + 1]) {
				Q.push(now + 1);
				Visit[now + 1] = true;
			}
			if (!Visit[now - 1] && now-1 >= 0) {
				Q.push(now - 1);
				Visit[now - 1];
			}
		}

		if (Find) {
			break;
		}

		cnt++;
	}
	cout << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	bfs();

	return 0;
}