#include <bits/stdc++.h>

using namespace std;

int R, C, Q;
int r1, r2, c1, c2;
int total[1001][1001];

int mother() {
	int ans1 = (r2 - r1 + 1);
	int ans2 = (c2 - c1 + 1);
	return ans1 * ans2;
}

int solution() {
	int ans = 0;
	for (int i = r1; i <= r2; i++) {
		if (c1 == 0)
			ans += total[i][c2];
		else
			ans += total[i][c2] - total[i][c1 - 1];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> Q;
	int temp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> temp;
			if (j == 0)
				total[i][j] = temp;
			else
				total[i][j] = temp + total[i][j - 1];
		}
	}

	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		cout << solution()/mother() << '\n';
	}

	return 0;
}