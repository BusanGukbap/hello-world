#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	double total = 0, maxx = 0;
	for (int i = 0; i < N; i++) {
		double temp;
		cin >> temp;
		total += temp;
		if (maxx < temp)
			maxx = temp;
	}
	total /= 2;
	total += maxx / 2;
	cout << total;

	return 0;
}