#include <bits/stdc++.h>

using namespace std;

void func(int n, int s, int e) {
	if (n == 1) {
		cout << s << " " << e << '\n';
		return;
	}

	func(n - 1, s, 6 - s - e);
	cout << s << " " << e << '\n';
	func(n - 1, 6 - s - e, e);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	cout << (1<<N) - 1 << '\n';
	func(N, 1, 3);

	return 0;
}