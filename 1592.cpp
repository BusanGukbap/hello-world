#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M, L;
vector <int> arr;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> L;
	for (int i = 0; i < N; i++)
		arr.push_back(0);

	int now = 0;
	int cnt = 0;
	while (1) {
		arr[now]++;
		if (arr[now] == M)
			break;
		cnt++;
		if (arr[now] % 2 == 1) {
			now = (now + L) % N;
		}
		else {
			now -= L;
			if (now < 0)
				now += N;
		}
	}

	cout << cnt;

	return 0;
}