#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, K;
bool Visit[200000];

bool range_in(int n) {
	return(n >= 0 && n <= 100000 && !Visit[n]);
}

void bfs() {
	queue<pair<int, int>> Q;
	Q.push({ N, 0 });
	int res = 100000;

	while (!Q.empty()) {
		int subin = Q.front().first;
		int clock = Q.front().second;
		Q.pop();
		Visit[subin] = true;

		if (subin == K) {
			if (clock < res)
				res = clock;
			continue;
		}

		if (range_in(subin*2)) {
			Q.push({ subin * 2, clock});
		}
		if (range_in(subin - 1)) {
			Q.push({ subin - 1, clock + 1 });
		}
		if (range_in(subin + 1)) {
			Q.push({ subin + 1, clock + 1 });
		}

	}


	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	bfs();
	
	return 0;
}