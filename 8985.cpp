#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int Test_case, cnt, total;
	string s;
	cin >> Test_case;

	for (int i = 0; i < Test_case; i++) {
		cin >> s;
		cnt = total = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'X')
				cnt = 0;
			else
				cnt++;
			total += cnt;
		}
		cout << total << '\n';
	}

	return 0;
}