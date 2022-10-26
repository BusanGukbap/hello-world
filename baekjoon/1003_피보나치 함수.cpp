#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int fibo[41][2];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int Test_case, N;
	cin >> Test_case;

	fibo[0][0] = 1;
	fibo[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}

	for (int i = 0; i < Test_case; i++) {
		cin >> N;
		cout << fibo[N][0] << " " << fibo[N][1] << '\n';
	}


	return 0;
}