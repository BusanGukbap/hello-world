#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int X, Y, Z;

	cin >> X >> Y;
	Z = (Y * 100) / X;

	if (Z >= 99) {
		cout << -1 << '\n';
		return 0;
	}

	int ans = -1;
	int low = 0, high = MAX;
	while (low <= high) {
		int mid = (low + high) / 2;
		int tempZ = (100 * (Y + mid)) / (X + mid);

		if (Z >= tempZ) {
			ans = mid + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans << '\n';

	return 0;
}