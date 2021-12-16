#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}

		cout << a + b << '\n';
	}

	return 0;
}