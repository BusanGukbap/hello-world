#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
long long int K;
long long int arr[1000000];
long long int minn = 1000000000;
long long int ans;

void solution() {
	long long int start = minn;
	long long int end = minn + K;

	while (start <= end) {
		long long int mid = (start + end) / 2;
		
		long long int sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid > arr[i])
				sum += mid - arr[i];
		}

		if (sum <= K) {
			start = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else
			end = mid - 1;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < minn)
			minn = arr[i];
	}

	solution();

	cout << ans;

	return 0;
}