#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j * i <= n; j++) {
			if (j * i <= n)
				res++;
		}
	}

	cout << res;

	return 0;
}