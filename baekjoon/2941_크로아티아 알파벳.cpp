#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;

	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'j') {
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
				continue;
			else
				cnt++;
		}
		else if (str[i] == '=') {
			if (str[i - 1] == 'z' && str[i - 2] == 'd') {
				cnt--;
				continue;
			}
			else if (str[i - 1] == 'z' || str[i - 1] == 's' || str[i - 1] == 'c')
				continue;
		}
		else if (str[i] == '-')
			continue;
		else
			cnt++;
	}

	cout << cnt;

	return 0;
}