#define _CRT_SECURE_NO_WARNINIGS

#include <bits/stdc++.h>

using namespace std;

int T, x, y;

void func(int len) {
	int temp = sqrt(len);
	if (temp * temp == len) {
		cout << temp * 2 - 1 << '\n';
		return;
	}
	else {
		int temp2 = (temp + 1);
		if (temp2 * temp2 - len > len - temp * temp) {
			cout << temp * 2 << '\n';
		}
		else
			cout << temp * 2 + 1 << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> x >> y;
		int len = y - x;
		func(len);
	}

	return 0;
}