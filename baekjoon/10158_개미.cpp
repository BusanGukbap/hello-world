#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int w, h, p, q, t;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> h >> p >> q >> t;
	int x, y;
	int a = (t + p) / w;
	int b = (t + p) % w;
	
	if (a % 2 == 0)
		x = b;
	else
		x = w - b;

	a = (t + q) / h;
	b = (t + q) % h;
	
	if (a % 2 == 0)
		y = b;
	else
		y = h - b;
	
	cout << x << " " << y;

	return 0;
}