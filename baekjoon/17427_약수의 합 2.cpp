#define _CRT_SECURE_NO_WRANINGS

#include <bits/stdc++.h>

using namespace std;

long long N, arr[1000001];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (long long idx = 1; idx <= N; idx++) {
		for (long long j = idx; j <= N; j += idx) {
			arr[j] += idx;
		}
	}
	for (long long idx = 1; idx <= N; idx++) {
		arr[idx] += arr[idx - 1];
	}
	cout << arr[N];

	return 0;
}