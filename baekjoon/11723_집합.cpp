#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string str;
	int temp, BIT = 0;
	
	while (N--) {
		cin >> str;
		if (str == "add") {
			cin >> temp;
			BIT |= (1 << temp);
		}
		else if (str == "remove") {
			cin >> temp;
			BIT &= ~(1 << temp);
		}
		else if (str == "check") {
			cin >> temp;
			if (BIT & (1 << temp))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "toggle") {
			cin >> temp;
			BIT ^= (1 << temp);
		}
		else if (str == "all") {
			BIT = (1 << 21) - 1;
		}
		else if (str == "empty") {
			BIT = 0;
		}
	}


	return 0;
}