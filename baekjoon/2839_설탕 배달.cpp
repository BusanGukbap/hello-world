#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int five = N / 5;
	int three = (N % 5) / 3;
	int temp = (N % 5) % 3;

	while (1) {
		if (five < 0) {
			cout << -1;
			break;
		}
		if (temp == 0) {
			cout << three + five;
			break;
		}
		
		five--;
		temp += 5;
		three += temp / 3;
		temp %= 3;
	}

	
	return 0;
}