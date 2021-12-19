#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int original = N;
	int temp = -1;
	int cnt = 0;
	for (; ;) {
		temp = N % 10 + N / 10;
		N = (N % 10) * 10 + temp % 10;
		cnt++;
		
		if (original == N) {
			cout << cnt;
			break;
		}
	}

	return 0;
}