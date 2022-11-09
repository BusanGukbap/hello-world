#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int sheep, fox, start=0, end = N-1;
	int temp;
	for (int i = 0; i < 20; i++) {
		int day = (start + end) / 2;

		cout << "? " << day << endl;
		cin >> sheep;

		fox = day - sheep;

		if (sheep > fox) {
			start = day + 1;
		}
		else if (sheep < fox) {
			end = day - 1;
		}
		else if (sheep == fox) {
			T = day;
			break;
		}
	}

	cout << "! " << T << endl;
}