#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, X;
int T[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> T[i];
	
	int cnt = X;
	int index = 0;
	while (1) {
		if (T[index % N] < cnt) {
			cout << index % N + 1 << '\n';
			break;
		}
		index++;
		cnt++;
	}

	return 0;
}