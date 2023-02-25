#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

// (인기도) = (구간의 초당 인기도 합) / (구간의 길이)
// 24*60*60 = 86400
int N, M;

ld tree[1000000];

int changeClock(string str) {
	int hour = (str[0] - '0') * 10 + (str[1] - '0');
	int minute = (str[3] - '0') * 10 + (str[4] - '0');
	int second = (str[6] - '0') * 10 + (str[7] - '0');

	return (1 + second + minute * 60 + hour * 3600);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str1, str2, str3;
		cin >> str1 >> str2 >> str3;
		int t1 = changeClock(str1), t2 = changeClock(str3);

		// tree[i] = (i)인기도 - (i-1)인기도

		tree[t1]++;
		if (t2 + 1 <= 24 * 60 * 60)
			tree[t2 + 1]--;
		if (t1 > t2)
			tree[1]++;
	}

	// tree[i] = (i)인기도
	for (int i = 1; i <= 24 * 60 * 60; i++)
		tree[i] += tree[i - 1];
	// tree[i] = (i)까지의 인기도 누적합
	for (int i = 1; i <= 24 * 60 * 60; i++) {
		tree[i] += tree[i - 1];
	}

	cin >> M;

	cout << fixed;
	cout.precision(10);

	
	for (int i = 1; i <= M; i++) {
		string str1, str2, str3;
		cin >> str1 >> str2 >> str3;

		int t1 = changeClock(str1), t2 = changeClock(str3);
		ld total = 0;

		if (t1 <= t2) {
			total = tree[t2] - tree[t1 - 1];
			cout << (ld)total / (t2 - t1 + 1) << '\n';
		}
		else {
			total = tree[24 * 60 * 60] - tree[t1 - 1] + tree[t2];
			cout << (ld)total / (24 * 60 * 60 - t1 + 1 + t2) << '\n';
		}
	}


	return 0;
}