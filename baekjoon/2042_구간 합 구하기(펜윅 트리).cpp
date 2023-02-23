#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, K;
ll arr[1000001];
ll Tree[1000001];

void update(ll num, int idx) {
	while (idx <= N) {
		Tree[idx] += num;
		idx += (idx & -idx);
	}
}

ll sum(int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += Tree[idx];
		idx -= (idx & -idx);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(arr[i], i);
	}

	for (int i = 1; i <= (M + K); i++) {
		int a, b;
		ll c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			ll diff = c - arr[b];
			arr[b] = c;
			update(diff, b);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << sum(c) - sum(b - 1) << '\n';
		}
	}


	return 0;
}