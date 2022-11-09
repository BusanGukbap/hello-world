#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int M, N;
long long int arr[1000000];
long long int ans;
long long int maxx = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (maxx < arr[i])
			maxx = arr[i];
	}
	
	long long int start = 0, end = maxx;
	while (start <= end) {
		long long int mid = (start + end) / 2;
		if (mid == 0) {
			break;
		}
		long long int cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt >= M) {
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}

	cout << ans;

	return 0;
}