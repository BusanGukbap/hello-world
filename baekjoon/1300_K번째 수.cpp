#include <bits/stdc++.h>

using namespace std;

int N, K;

// 1 2 3  4   
// 2 4 6  8
// 3 6 9  12
// 4 8 12 16


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	
	int left = 1, right = K;
	int res;
	
	for (;;) {
		if (left > right)
			break;

		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		
		
		if (cnt < K) {
			left = mid + 1;
		}
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res << '\n';

	return 0;
}