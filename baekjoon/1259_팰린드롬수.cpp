#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

void palindrome(int input) {
	int save = input;
	int temp = 0;
	while (input > 0) {
		temp *= 10;
		temp += input % 10;
		input /= 10;
	}
	if (temp - save == 0)
		cout << "yes\n";
	else
		cout << "no\n";
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	while (1) {
		cin >> n;
		if (n == 0)
			break;
		palindrome(n);
	}



	return 0;
}