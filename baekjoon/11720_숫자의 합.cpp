#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, total = 0;
	string temp;
	cin >> N >> temp;
	for (int i = 0; i < N; i++) {
		total += temp[i] - '0';
	}

	cout << total;

	return 0;
}