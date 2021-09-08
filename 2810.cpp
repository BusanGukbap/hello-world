#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> s;

	int cnt = 1;
	int L = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'S')
			cnt++;
		else {
			L++;
			if (L == 2) {
				cnt++;
				L = 0;
			}
		}
	}

	cout << min(cnt, N);



	return 0;
}