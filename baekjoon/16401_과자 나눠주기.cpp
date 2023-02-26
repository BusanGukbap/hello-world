#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int M, N;
ll arr[1000000];
ll ans = 0;
ll maxx = 0;

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

	ll start = 1, end = maxx;
	while (start <= end) {
		ll mid = (start + end) / 2;
		if (mid == 0) {
			break;
		}
		ll cnt = 0;

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

	cout << ans << '\n';

	return 0;
}