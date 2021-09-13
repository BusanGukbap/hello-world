#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int total = 1;
	int i = 0;
	while (1) {
		if (N <= total) {
			cout << i+1;
			break;
		}
		total += (i + 1) * 6;
		i++;
	}

	return 0;
}