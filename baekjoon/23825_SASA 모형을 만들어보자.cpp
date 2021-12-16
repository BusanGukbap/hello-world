#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	if (N > M)
		cout << M / 2;
	else
		cout << N / 2;

	return 0;
}