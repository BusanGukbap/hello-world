#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<int>arr(N);
	vector<int>cnt(N , 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int now = 0; now < N; now++) {
		double maxx = -9999999999;
		for (int i = now + 1; i < N; i++) {
			double level = (double)(arr[i] - arr[now]) / (i - now);
			if (level > maxx) {
				cnt[now]++;
				cnt[i]++;
				maxx = level;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, cnt[i]);
	}

	cout << res;

	return 0;
}