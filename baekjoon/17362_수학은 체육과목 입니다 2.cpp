#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	n %= 8;
	if (n == 0)
		n = 2;
	else if (n > 5)
		n = 10 - n;

	cout << n;

	return 0;
}