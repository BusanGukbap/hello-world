#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int max = 0, index = 0, temp;
	for (int i = 1; i <= 9; i++) {
		cin >> temp;
		if (temp > max) {
			max = temp;
			index = i;
		}
	}

	cout << max << '\n' << index;

	return 0;
}