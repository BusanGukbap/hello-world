#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long double p[10];
	for (int i = 0; i < 10; i++)
		cin >> p[i];

	sort(p, p + 10, greater<>());

	long double ans = 1;
	for (int i = 0; i < 9; i++) {
		ans = ans * p[i] / (i + 1);
	}

	cout.precision(15);
	cout << ans * 1000000000;

	return 0;
}