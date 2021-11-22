#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string temp;
	cin >> temp;

	bool driip = true;
	int len = temp.length() - 1;
	if (temp[len--] != 'p')
		driip = false;
	if (temp[len--] != 'i')
		driip = false;
	if (temp[len--] != 'i')
		driip = false;
	if (temp[len--] != 'r')
		driip = false;
	if (temp[len--] != 'd')
		driip = false;
	if (driip)
		cout << "cute";
	else
		cout << "not cute";

	return 0;
}