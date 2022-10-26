#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int total = a * a + b * b + c * c + d * d + e * e;

	cout << total % 10;

	return 0;
}