#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	srand(time(NULL));
	for (int i = 0; i < 814; i++) {
		cout << rand() % 16280 - 8140 << " ";
		cout << rand() % 16280 - 8140 << '\n';
	}

	return 0;
}