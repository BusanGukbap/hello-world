#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, temp;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0)
			break;

		if (a > c) {
			temp = c;
			c = a;
			a = temp;
		}
		if (b > c) {
			temp = c;
			c = b;
			b = temp;
		}
		
		if (c * c == b * b + a * a)
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}